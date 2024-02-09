add_definitions(-DTRANSLATION_DOMAIN=\"plasma_applet_org.kde.plasma.ipaddr\")

add_library(ipaddrplugin SHARED ipaddrplugin.cpp)

target_link_libraries(ipaddrplugin
    KF5::I18n
    Qt5::Gui
    Qt5::Qml
    Qt5::Network
)
install(TARGETS ipaddrplugin DESTINATION ${KDE_INSTALL_QMLDIR}/org/kde/plasma/private/ipaddr)
install(FILES qmldir DESTINATION ${KDE_INSTALL_QMLDIR}/org/kde/plasma/private/ipaddr)
