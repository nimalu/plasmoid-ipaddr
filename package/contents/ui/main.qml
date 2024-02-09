/*
    SPDX-FileCopyrightText: 2024 Niklas Lutze <nl@niklaslutze.de>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

import QtQuick 2.1
import QtQuick.Layouts 1.1
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.plasmoid 2.0
import org.kde.plasma.components 2.0 as PlasmaComponents



Item {
    Plasmoid.preferredRepresentation: Plasmoid.fullRepresentation

    property var ipAddress: ""

    PlasmaCore.DataSource {
        id: dataSource
        engine: "executable"
        connectedSources: ["ifconfig | grep \"inet \" | grep -Fv 127.0.0.1 | awk '{print $2}'"]
        interval: 10000
        onNewData: {
            ipAddress = data.stdout.trim()
        }
    }

    Plasmoid.fullRepresentation: ColumnLayout {
        anchors.fill: parent
        PlasmaComponents.Label {
            Layout.alignment: Qt.AlignCenter
            text: ipAddress
        }
    }
}
