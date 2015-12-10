//#include <QDebug>

#include "zbc_drivebuttonswidget.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QStorageInfo>

#include <windows.h>

//C-tor
ZBC_DriveButtonsWidget::ZBC_DriveButtonsWidget(const QStringList& lstPath, QWidget* pwgt) : QFrame(pwgt)
{
    QSignalMapper* psglMapper   = new QSignalMapper(this);
    QHBoxLayout* pLayout        = new QHBoxLayout(this);
    pLayout->setSpacing(0);
    pLayout->setMargin(0);

    for( QString sPath : lstPath ){
        QPushButton* pBtn   = new QPushButton(QIcon(":/buttons/drives/resource/logicaldrive.ico"), sPath, this);
        pBtn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        QStorageInfo* pStorInfo = new QStorageInfo(sPath);
        pBtn->setToolTip(pStorInfo->displayName());
//        qDebug() << pStorInfo->device();
        delete pStorInfo;
        pBtn->setFocusPolicy(Qt::NoFocus);
        pBtn->setFixedSize(pBtn->sizeHint());

        connect(pBtn,
                &QPushButton::clicked,
                psglMapper,
                static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map));
        psglMapper->setMapping(pBtn, sPath);
        pLayout->addWidget(pBtn);
    }

    connect(psglMapper,
            static_cast<void (QSignalMapper::*)(const QString&)>(&QSignalMapper::mapped),
            this,
            &ZBC_DriveButtonsWidget::clicked);

    setFrameStyle(QFrame::Box | QFrame::Sunken);
    setFixedHeight(minimumSizeHint().height());
    setLayout(pLayout);
}
