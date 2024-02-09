/*
    SPDX-FileCopyrightText: 2024 Niklas Lutze <nl@niklaslutze.de>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/
#include <iostream>

#include "ipaddrplugin.h"

// KF
#include <KLocalizedString>
// Qt
#include <QJSEngine>
#include <QQmlEngine>
#include <QQmlContext>

#include <QHostInfo>
#include <QNetworkInterface>

static QJSValue singletonTypeExampleProvider(QQmlEngine* engine, QJSEngine* scriptEngine)
{
    Q_UNUSED(engine)
    QJSValue networkInfo = scriptEngine->newObject();

    QString hostName = QHostInfo::localHostName();
    networkInfo.setProperty("hostname", hostName);

    QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
    foreach (const QHostAddress &address, addresses) {
        QString ipAddress = address.toString();
        if (ipAddress.startsWith("192.")) {
            networkInfo.setProperty("ipAddress", ipAddress);
        }
    }

    return networkInfo;
}


void ipaddrPlugin::registerTypes(const char* uri)
{
    Q_ASSERT(uri == QLatin1String("org.kde.plasma.private.ipaddr"));

    qmlRegisterSingletonType(uri, 1, 0, "NetworkInfo", singletonTypeExampleProvider);
}

#include "moc_ipaddrplugin.cpp"
