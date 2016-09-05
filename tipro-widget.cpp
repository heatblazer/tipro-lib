#include "tipro-widget.h"
#include <iostream>
#include <QTimer>

namespace tipro {

TiproWidget::TiproWidget(QWidget *parent)
    : QWidget(parent)
{

// TODO: later add support for left and right module
    if(0){
        m_leftModule.widget = new QWidget();
        m_rightModule.widget = new QWidget();

        m_leftModule.widget->setMinimumSize(200, 200);
        m_leftModule.widget->setMaximumSize(200, 200);
        m_rightModule.widget->setMinimumSize(200, 200);
        m_rightModule.widget->setMaximumSize(200, 200);

        m_leftModule.widget->show();
        m_rightModule.widget->show();

    }
    {
        m_leds.label.setText("Test leds:");
        m_leds.led1.setText("LED 1");
        m_leds.led2.setText("LED 2");
        m_leds.led3.setText("LED 3");
        m_leds.led4.setText("LED 4");
        m_leds.testAllLeds.setText("Test all leds");


        m_leds.layout.addWidget(&m_leds.label);
        m_leds.layout.addWidget(&m_leds.led1);
        m_leds.layout.addWidget(&m_leds.led2);
        m_leds.layout.addWidget(&m_leds.led3);
        m_leds.layout.addWidget(&m_leds.led4);
        m_leds.layout.addWidget(&m_leds.testAllLeds);
        m_leds.timer.setInterval(1000);
        m_leds.toggle = false;
    }

    {
        m_screen.label.setText("Resistive screen:");
        m_screen.screen_off.setText("Screen OFF");
        m_screen.screen_on.setText("Screen ON");
        m_screen.layout.addWidget(&m_screen.label);
        m_screen.layout.addWidget(&m_screen.screen_on);
        m_screen.layout.addWidget(&m_screen.screen_off);
    }

    {
        m_brightness.text.setText("BRIGHTNESS:");
        m_brightness.slider = new QSlider(Qt::Horizontal);
        m_brightness.slider->setValue(10);
        // as in for tipro lib - level is between 0 and 20
        m_brightness.slider->setRange(0, 20);
        m_brightness.layout.addWidget(&m_brightness.text);
        m_brightness.layout.addWidget(m_brightness.slider);
    }

    {
        m_info.label.setText("Info tab:");
        m_info.text.setMinimumSize(400,150);
        m_info.text.setMaximumSize(400,150);
        m_info.text.setReadOnly(true);
        QPalette p = palette();
        p.setColor(QPalette::Base, Qt::black);
        p.setColor(QPalette::Text, Qt::green);
        m_info.text.setPalette(p);

        m_info.layout.addWidget(&m_info.label);
        m_info.layout.addWidget(&m_info.text);

    }

    {
        connect(&m_leds.led1, SIGNAL(clicked(bool)),
                this, SLOT(led1()));
        connect(&m_leds.led2, SIGNAL(clicked(bool)),
                this, SLOT(led2()));
        connect(&m_leds.led3, SIGNAL(clicked(bool)),
                this, SLOT(led3()));
        connect(&m_leds.led4, SIGNAL(clicked(bool)),
                this, SLOT(led4()));
        connect(&m_leds.testAllLeds, SIGNAL(clicked(bool)),
                this, SLOT(toggleLedTest()));
        connect(&m_leds.timer, SIGNAL(timeout()),
                this, SLOT(testAllLeds()));
       // connect(&m_leds.timer, SIGNAL(timeout()),
       //         this, SLOT(showInfo()));
    }

    {
        connect(m_brightness.slider, SIGNAL(valueChanged(int)),
                this, SLOT(setBrightness(int)));
    }
    {
        connect(&m_screen.screen_off, SIGNAL(clicked(bool)),
                this, SLOT(turnOffScreen()));
        connect(&m_screen.screen_on, SIGNAL(clicked(bool)),
                this, SLOT(turnOnScreen()));
    }

    m_layout.addLayout(&m_info.layout);

    m_layout.addLayout(&m_leds.layout);
    m_layout.addLayout(&m_brightness.layout);
    m_layout.addLayout(&m_screen.layout);

    setLayout(&m_layout);
    setMinimumSize(480, 480);
    setMaximumSize(480, 480);

    m_leds.timer.start();
    showInfo();
}

TiproWidget::~TiproWidget()
{

}

void TiproWidget::closeEvent(QCloseEvent *event)
{
    (void) event;
    cleanup();
}

int TiproWidget::led1()
{
    return TiproLib::Instance().setLeds(TIPRO_LED1);
}

int TiproWidget::led2()
{
    return TiproLib::Instance().setLeds(TIPRO_LED2);
}

int TiproWidget::led3()
{
    return TiproLib::Instance().setLeds(TIPRO_LED3);
}

int TiproWidget::led4()
{
    return TiproLib::Instance().setLeds(TIPRO_LED4);
}

void TiproWidget::toggleLedTest()
{
    m_leds.toggle ^= true;
}

void TiproWidget::testAllLeds()
{
    static int cnt = 0;
    if(m_leds.toggle) {
        if (cnt >= 16) {
            cnt = 0;
        } else {
            std::cout << "Testing led: " << cnt << std::endl;
            TiproLib::Instance().setLeds(cnt);
            cnt++;
        }
    }
}


int TiproWidget::setBrightness(int level)
{
    return TiproLib::Instance().setBrightness(level);
}

void TiproWidget::turnOffScreen()
{
    TiproLib::Instance().disableTouchScreen();
}

void TiproWidget::turnOnScreen()
{
    TiproLib::Instance().enableTouchScreen();
}

void TiproWidget::hTextChange()
{
    QTextCursor c(m_info.text.textCursor());
    c.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    m_info.text.setTextCursor(c);
}

void TiproWidget::cleanup()
{
    if (0) {
    if(m_leftModule.widget) {
        delete m_leftModule.widget;
    }
    if (m_rightModule.widget) {
        delete m_rightModule.widget;
    }
    }

}

void TiproWidget::showInfo()
{
    int devices = TiproLib::Instance().detectDevices();
    int enumModules = TiproLib::Instance().enumDevices();

    struct controller_info ci = TiproLib::Instance().getControllerInfo();

    static char txt[512] = {0};
    sprintf(txt, "Devices: [%d]\n"
            "Enumerated modules: [%d]\n"
            "Controller info:\n VerMaj:[%d]\nVerMin:[%d]\n"
            "VerBuild:[%d]\nVerCustom:[%d]\n"
            "FWLevel:[%d]\n",
            devices, enumModules,
            ci.verMaj, ci.verMin, ci.verBuild,
            ci.verCustom, ci.FWLevel);

    m_info.text.setPlainText(QString(txt));

}

} // namespace tipro

