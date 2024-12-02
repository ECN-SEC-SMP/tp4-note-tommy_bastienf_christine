# Ajouter Google Test
add_subdirectory(../googletest googletest-build)

# Activer les tests
enable_testing()

# Définir les fichiers sources et d'en-tête nécessaires
set(SOURCES
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
    ../headers/ZN.hpp
    ../headers/ZA.hpp
    ../headers/ZU.hpp
    ../headers/ZAU.hpp
    ../headers/Carte.hpp
    ../headers/Constructible.hpp
)

# Créer une bibliothèque statique avec les fichiers sources
add_library(my_library STATIC ${SOURCES} ${HEADERS})

# Définir les fichiers de test
set(TEST_SOURCES
    test.cpp
)

# Créer un exécutable pour chaque fichier de test unitaire
add_executable(test test.cpp)

# Lier Google Test et les fichiers sources aux exécutables de test unitaire
target_link_libraries(test my_library gtest gtest_main)

# Créer un exécutable global pour tous les tests unitaires
add_executable(all_tests ${TEST_SOURCES})

# Lier Google Test et les fichiers sources à l'exécutable global
target_link_libraries(all_tests my_library gtest gtest_main)

# Ajouter les tests
add_test(NAME test COMMAND test)