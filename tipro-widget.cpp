#include "tipro-widget.h"
#include <iostream>
namespace tipro {

TiproWidget::TiproWidget(QWidget *parent)
    : QWidget(parent)
{
    {
        m_leds.led1.setText("LED 1");
        m_leds.led2.setText("LED 2");
        m_leds.led3.setText("LED 3");
        m_leds.led4.setText("LED 4");
        m_leds.testAllLeds.setText("Test all leds");


        m_leds.layout.addWidget(&m_leds.led1);
        m_leds.layout.addWidget(&m_leds.led2);
        m_leds.layout.addWidget(&m_leds.led3);
        m_leds.layout.addWidget(&m_leds.led4);
        m_leds.layout.addWidget(&m_leds.testAllLeds);
        m_leds.timer.setInterval(1000);
        m_leds.toggle = false;
    }

    {
        m_screen.screen_off.setText("Screen OFF");
        m_screen.screen_on.setText("Screen ON");
        m_screen.layout.addWidget(&m_screen.screen_on);
        m_screen.layout.addWidget(&m_screen.screen_off);
    }

    {
        m_brightness.text.setText("BRIGHTNESS");
        m_brightness.slider = new QSlider(Qt::Horizontal);
        // as in for tipro lib - level is between 0 and 20
        m_brightness.slider->setRange(0, 20);
        m_brightness.layout.addWidget(&m_brightness.text);
        m_brightness.layout.addWidget(m_brightness.slider);
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

    m_layout.addLayout(&m_leds.layout);
    m_layout.addLayout(&m_brightness.layout);
    m_layout.addLayout(&m_screen.layout);

    setLayout(&m_layout);
    setMinimumSize(480, 480);
    setMaximumSize(480, 480);

    m_leds.timer.start();
}

TiproWidget::~TiproWidget()
{

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

} // namespace tipro

