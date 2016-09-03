#include "tipro-widget.h"

namespace tipro {

TiproWidget::TiproWidget(QWidget *parent)
    : QWidget(parent)
{
    {
        m_leds.led1.setText("LED 1");
        m_leds.led2.setText("LED 2");
        m_leds.led3.setText("LED 3");
        m_leds.led4.setText("LED 4");
        m_leds.layout.addWidget(&m_leds.led1);
        m_leds.layout.addWidget(&m_leds.led2);
        m_leds.layout.addWidget(&m_leds.led3);
        m_leds.layout.addWidget(&m_leds.led4);

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

