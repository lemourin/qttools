/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the tools applications of the Qt Toolkit.
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

/*
  doc.h
*/

#ifndef DOC_H
#define DOC_H

#include "location.h"

#include "ditaref.h"
#include "docutilities.h"
#include "topic.h"

#include <QtCore/qmap.h>
#include <QtCore/qset.h>
#include <QtCore/qstring.h>

QT_BEGIN_NAMESPACE

class Atom;
class CodeMarker;
class DocPrivate;
class Quoter;
class Text;

typedef QPair<QString, Location> ArgLocPair;
typedef QVector<ArgLocPair> ArgList;
typedef QMultiMap<QString, QString> QStringMultiMap;

class Doc
{
    Q_DECLARE_TR_FUNCTIONS(QDoc::Doc)

public:
    // the order is important
    enum Sections {
        NoSection = -2,
        Part = -1,
        Chapter = 1,
        Section1 = 1,
        Section2 = 2,
        Section3 = 3,
        Section4 = 4
    };

    Doc() = default;
    Doc(const Location &start_loc, const Location &end_loc, const QString &source,
        const QSet<QString> &metaCommandSet, const QSet<QString> &topics);
    Doc(const Doc &doc);
    ~Doc();

    Doc &operator=(const Doc &doc);

    const Location &location() const;
    const Location &startLocation() const;
    bool isEmpty() const;
    const QString &source() const;
    const Text &body() const;
    Text briefText(bool inclusive = false) const;
    Text trimmedBriefText(const QString &className) const;
    Text legaleseText() const;
    QSet<QString> parameterNames() const;
    QStringList enumItemNames() const;
    QStringList omitEnumItemNames() const;
    QSet<QString> metaCommandsUsed() const;
    TopicList topicsUsed() const;
    ArgList metaCommandArgs(const QString &metaCommand) const;
    QVector<Text> alsoList() const;
    bool hasTableOfContents() const;
    bool hasKeywords() const;
    bool hasTargets() const;
    bool isInternal() const;
    bool isMarkedReimp() const;
    const QVector<Atom *> &tableOfContents() const;
    const QVector<int> &tableOfContentsLevels() const;
    const QVector<Atom *> &keywords() const;
    const QVector<Atom *> &targets() const;
    QStringMultiMap *metaTagMap() const;

    static void initialize();
    static void terminate();
    static QString alias(const QString &english);
    static void trimCStyleComment(Location &location, QString &str);
    static QString resolveFile(const Location &location, const QString &fileName,
                               QString *userFriendlyFilePath = nullptr);
    static CodeMarker *quoteFromFile(const Location &location, Quoter &quoter,
                                     const QString &fileName);
    static QString canonicalTitle(const QString &title);

private:
    void detach();
    DocPrivate *priv { nullptr };
    static DocUtilities &m_utilities;
};
Q_DECLARE_TYPEINFO(Doc, Q_MOVABLE_TYPE);
typedef QVector<Doc> DocList;

QT_END_NAMESPACE

#endif
