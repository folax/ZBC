#include "zbc_styles.h"

#include <QPalette>
#include <QStyleFactory>

ZBC_SimpleStyle::ZBC_SimpleStyle() :
    QProxyStyle(QStyleFactory::create("Fusion"))
{}

void ZBC_SimpleStyle::polish(QPalette &darkPalette)
{
        darkPalette.setColor(QPalette::Window, QColor(53,53,53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(25,25,25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(0,102,0));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);
}
