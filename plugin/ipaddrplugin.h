/*
    SPDX-FileCopyrightText: 2024 Niklas Lutze <nl@niklaslutze.de>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef IPADDRPLUGIN_H
#define IPADDRPLUGIN_H

#include <QQmlExtensionPlugin>

class ipaddrPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri) override;
};

#endif // IPADDRPLUGIN_H
