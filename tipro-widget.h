#ifndef TIPROWIDGET_H
#define TIPROWIDGET_H

// qt headers //
#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QTimer>
#include <QPlainTextEdit>

// tipro lib //
#include "tipro-lib.h"

namespace tipro {

class TiproWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TiproWidget(QWidget* parent=nullptr);
    virtual ~TiproWidget();
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    int led1();
    int led2();
    int led3();
    int led4();
    void toggleLedTest();
    void testAllLeds();
    int setBrightness(int level);
    void turnOffScreen();
    void turnOnScreen();
    void hTextChange();
    void cleanup();
    void showInfo();

private:
    QVBoxLayout m_layout;
    struct {
        QLabel label;
        QPushButton led1;
        QPushButton led2;
        QPushButton led3;
        QPushButton led4;
        QPushButton testAllLeds;
        QHBoxLayout layout;
        QTimer timer;
        bool toggle;
    } m_leds;

    struct {
        QLabel label;
        QPushButton screen_off;
        QPushButton screen_on;
        QHBoxLayout layout;
    } m_screen;

    struct {
        // screen lights
        QLabel   text;
        QSlider* slider;
        QHBoxLayout layout;
    } m_brightness;

    struct {
        // info bar
        QPlainTextEdit text;
        QLabel          label;
        QHBoxLayout layout;

    } m_info;

    struct {
        QWidget* widget;
        QVBoxLayout layout;
        // future modules
    } m_leftModule;

    struct {
        QWidget* widget;
        QVBoxLayout layout;
        // future modules
    } m_rightModule;

    QObject m_resources;

};

} // namespace tipro


#endif // TIPROWIDGET_H
