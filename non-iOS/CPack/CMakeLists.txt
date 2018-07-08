#General Packaging Stuff
set(CPACK_DISPLAY_NAME "OpenDragon Debugging Library")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ODL Package")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "ODL")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY_ "odl")
set(CPACK_PACKAGE_NAME "ODL")
set(CPACK_PACKAGE_VERSION "${ODL_VERSION_STRING}")
set(CPACK_PACKAGE_VERSION_MAJOR "${ODL_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${ODL_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${ODL_VERSION_PATCH}")
set(CPACK_RESOURCE_FILE_LICENSE "${ODL_SOURCE_DIR}/../LICENSE")
set(CPACK_RESOURCE_FILE_README "${ODL_SOURCE_DIR}/../README.md")
set(CPACK_VENDOR "OpenDragon")

#display name for our components
set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C++ Header Files")
set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "ODL Libraries")

#descriptions for our components
set(CPACK_COMPONENT_HEADERS_DESCRIPTION "The header files required for new development")
set(CPACK_COMPONENT_LIBRARIES_DESCRIPTION "The fundamental files for an ODL installation")

#set up dependencies
set(CPACK_COMPONENT_HEADERS_DEPENDS libraries)

#set up CPack groups
set(CPACK_COMPONENT_HEADERS_GROUP "Core")
set(CPACK_COMPONENT_LIBRARIES_GROUP "Core")

#set up CPack constraints
set(CPACK_COMPONENT_LIBRARIES_REQUIRED ON)

#CPack group descriptions
set(CPACK_COMPONENT_GROUP_CORE_DESCRIPTION "The core ODL")
set(CPACK_COMPONENT_GROUP_CORE_BOLD_TITLE ON)

set(CPACK_COMPONENTS_ALL headers libraries)

#end General Packaging stuff

# platform independent install step:
#
# NOTE: since we're not currently using CPack on mac, everything falls under WIN32 below:
#

#Windows specific install step
if(WIN32)
    set(CPACK_GENERATOR NSIS)

    set(CPACK_NSIS_MODIFY_PATH ON)
    set(CPACK_NSIS_URL_INFO_ABOUT "http://www.mplusm.ca")

    #Finally, set some ODL Environment variables (WINDOWS ONLY!)
    set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS
        "
        CreateDirectory 'C:\\\\Users\\\\Public\\\\Documents\\\\m+m'
        WriteRegStr HKCU 'Environment' 'ODL_ROOT' '$INSTDIR'
        ")

    #And, unset them when we uninstall!
    set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS
        "
        DeleteRegValue HKCU 'Environment' 'ODL_ROOT'
        ")

endif()

include(CPack)
