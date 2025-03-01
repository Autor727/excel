include(F:/Qt/excel/build/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/excel-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_ALL_MODULES_FOUND_VIA_FIND_PACKAGE "ZlibPrivate;EntryPointPrivate;Core;Gui;Widgets;AxBasePrivate;AxContainer")

qt6_deploy_runtime_dependencies(
    EXECUTABLE F:/Qt/excel/build/excel.exe
    GENERATE_QT_CONF
)
