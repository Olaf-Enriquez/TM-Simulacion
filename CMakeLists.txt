#Version de CMake
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
#Nombre proyecto
project(TM_Simulacion)
#Encontrar paquetes de usuario y visuales de Geant4
find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})#Guardar cierto tipo de archivo
include_directories(${PROJECT_SOURCE_DIR}/include)#Incluir folder /include
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)#Incluir sources .cc en carpeta /src para construcción
file(GLOB MACRO_FILES "Macros/*.mac")#Ubicacion macros
file(COPY ${MACRO_FILES} DESTINATION ${CMAKE_BINARY_DIR}/)#Copiar macros a carpeta principal
add_executable(TM_Sim TM_Sim.cc ${sources})#Nombrar archivo ejecutable, .cc archivo source
target_link_libraries(TM_Sim ${Geant4_LIBRARIES}) #Incluir lib en ejecutable también
add_custom_target(Sim1 DEPENDS TM_Sim)

