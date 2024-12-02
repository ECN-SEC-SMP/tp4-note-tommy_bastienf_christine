# Ajouter les fichiers source et d'en-tête
set(SOURCES
    ../src/main.cpp
    ../src/Parcelle.cpp
    ../src/ZN.cpp
    ../src/ZA.cpp
    ../src/ZU.cpp
    ../src/ZAU.cpp
    ../src/Carte.cpp
    ../src/Constructible.cpp
)

set(HEADERS
    ../headers/Point2D.hpp
    ../headers/Polygone.hpp
    ../headers/Parcelle.hpp
    ../headers/Constructible.hpp
    ../headers/ZN.hpp
    ../headers/ZA.hpp
    ../headers/ZU.hpp
    ../headers/ZAU.hpp
    ../headers/Carte.hpp
)

# Créer l'exécutable
add_executable(main ${SOURCES} ${HEADERS})