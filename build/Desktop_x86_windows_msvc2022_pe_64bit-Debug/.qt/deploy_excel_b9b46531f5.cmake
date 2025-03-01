include(F:/Qt/excel/build/Desktop_x86_windows_msvc2022_pe_64bit-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/excel-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_ALL_MODULES_FOUND_VIA_FIND_PACKAGE "ZlibPrivate;EntryPointPrivate;Core;Gui;Widgets;AxBasePrivate;AxContainer")

qt6_deploy_runtime_dependencies(
    EXECUTABLE F:/Qt/excel/build/Desktop_x86_windows_msvc2022_pe_64bit-Debug/excel.exe
    GENERATE_QT_CONF
)
