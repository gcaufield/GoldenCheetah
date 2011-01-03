/*
 * Copyright (c) 2010 Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_DiaryWindow_h
#define _GC_DiaryWindow_h 1

#include "GoldenCheetah.h"

#include <QtGui>
#include <QCalendarWidget>
#include <QStackedWidget>

#include "MainWindow.h"
#include "RideMetadata.h"

// list view
#include "RideNavigator.h"

// weekly view
#include "qxtscheduleview.h"
#include "QxtScheduleViewProxy.h"
#include "WeeklyViewItemDelegate.h"

// monthly view
#include <QTableView>
#include "GcCalendarModel.h"

// ride view
#include "RideSummaryWindow.h"


class DiaryWindow : public GcWindow
{
    Q_OBJECT
    G_OBJECT

    Q_PROPERTY(int view READ view WRITE setView USER true)

    public:

        DiaryWindow(MainWindow *);

        int view() const { return viewMode->currentIndex(); }
        void setView(int x) { viewMode->setCurrentIndex(x); }

    public slots:
        void rideSelected();
        void configChanged();
        void nextClicked();
        void prevClicked();
        void weeklySelected(QModelIndex);
        void setDefaultView(int);
        bool eventFilter(QObject *object, QEvent *e); // traps monthly view

    protected:
        MainWindow *mainWindow;

        QLabel *title;
        QPushButton *prev, *next;

        QComboBox *viewMode;
        QStackedWidget *allViews;
        RideNavigator *listView;

        QTableView *monthlyView;
        GcCalendarModel *calendarModel;

        QxtScheduleView *weeklyView;
        QxtScheduleViewProxy *weeklyViewProxy;

        bool active;
        QList<FieldDefinition> fieldDefinitions;
};
#endif // _GC_DiaryWindow_h
