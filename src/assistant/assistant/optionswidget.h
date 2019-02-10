/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Assistant of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include <QtWidgets/QWidget>
#include <QtCore/QMap>

QT_BEGIN_NAMESPACE

class QListWidget;
class QListWidgetItem;

class OptionsWidget : public QWidget
{
    Q_OBJECT
public:
    OptionsWidget(QWidget *parent = nullptr);

    void clear();
    void setOptions(const QStringList &validOptions,
                    const QStringList &selectedOptions);
    QStringList validOptions() const;
    QStringList selectedOptions() const;

signals:
    void optionSelectionChanged(const QStringList &options);

private:
    QListWidgetItem *appendItem(const QString &optionName, bool valid, bool selected);
    void appendSeparator();
    void itemChanged(QListWidgetItem *item);

    QListWidget *m_listWidget = nullptr;
    QStringList m_validOptions;
    QStringList m_invalidOptions;
    QStringList m_selectedOptions;
    QMap<QString, QListWidgetItem *> m_optionToItem;
    QMap<QListWidgetItem *, QString> m_itemToOption;
};

QT_END_NAMESPACE

#endif  // OPTIONSWIDGET_H