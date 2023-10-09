# CMakeList.txt : projet CMake pour List, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (List "main.cpp" "List.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET List PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
