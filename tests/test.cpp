#include <gtest/gtest.h>
#include "../headers/Point2D.hpp"
#include "../headers/Polygone.hpp"
#include "../headers/Parcelle.hpp"
#include "../headers/ZAU.hpp"
#include "../headers/ZN.hpp"
#include "../headers/ZU.hpp"
#include "../headers/ZA.hpp"
#include "../headers/Constructible.hpp"


// Tests pour Polygone
TEST(Polygone, Constructor) {
    {
        SCOPED_TRACE("Testing default constructor");
        Polygone<int> poly;
        EXPECT_TRUE(poly.getSommets().empty());
    }

    {
        SCOPED_TRACE("Testing parameterized constructor");
        std::vector<Point2D<int>> points = { Point2D<int>(1, 1), Point2D<int>(2, 3), Point2D<int>(4, 5) };
        Polygone<int> poly(points);
        EXPECT_EQ(poly.getSommets().size(), 3);
        EXPECT_EQ(poly.getSommets()[0].getX(), 1);
        EXPECT_EQ(poly.getSommets()[1].getY(), 3);
    }
}

TEST(Polygone, AddPoint) {
    Polygone<int> poly;
    poly.addPoint(Point2D<int>(1, 1));
    EXPECT_EQ(poly.getSommets().size(), 1);
    EXPECT_EQ(poly.getSommets()[0].getX(), 1);
    EXPECT_EQ(poly.getSommets()[0].getY(), 1);
}

TEST(Polygone, Translate) {
    std::vector<Point2D<int>> points = { Point2D<int>(1, 1), Point2D<int>(2, 3), Point2D<int>(4, 5) };
    Polygone<int> poly(points);
    poly.translate(2, -1);
    EXPECT_EQ(poly.getSommets()[0].getX(), 3);
    EXPECT_EQ(poly.getSommets()[0].getY(), 0);
}

// Tests pour Parcelle
TEST(Parcelle, Constructor) {
    std::vector<Point2D<int>> points = { Point2D<int>(0, 0), Point2D<int>(4, 0), Point2D<int>(4, 3), Point2D<int>(0, 3) };
    Polygone<int> poly(points);
    Parcelle parcelle(1, "Al Capone", poly);

    EXPECT_EQ(parcelle.getNumero(), 1);
    EXPECT_EQ(parcelle.getProprietaire(), "Tony Montana");
    EXPECT_EQ(parcelle.getSurface(), 12); // Surface calculée : 4*3 = 12
}

TEST(Parcelle, InvalidPolygon) {
    std::vector<Point2D<int>> points = { Point2D<int>(0, 0), Point2D<int>(4, 0) };
    EXPECT_THROW(Parcelle parcelle(1, "Tony Soprano", Polygone<int>(points)), std::invalid_argument);
}

// Tests pour les zones spécifiques
TEST(ZAU, Properties) {
    std::vector<Point2D<int>> points = { Point2D<int>(0, 0), Point2D<int>(4, 0), Point2D<int>(4, 3), Point2D<int>(0, 3) };
    Polygone<int> poly(points);
    ZAU zau(1, "Tommy DeVito", poly);

    EXPECT_EQ(zau.getType(), "Zone Agricole Urbaine");
    EXPECT_EQ(zau.getSurfaceConstructible(), 87); // Hypothèse pour la surface constructible
}

TEST(ZN, NonConstructible) {
    std::vector<Point2D<int>> points = { Point2D<int>(1, 1), Point2D<int>(5, 1), Point2D<int>(5, 4), Point2D<int>(1, 5) };
    Polygone<int> poly(points);
    ZN zn(2, "Publique", poly);

    EXPECT_EQ(zn.getType(), "Zone Naturelle");
    EXPECT_EQ(zn.getSurface(), 14); // Surface calculée
    
}

TEST(ZU, UrbanZoneProperties) {
    std::vector<Point2D<int>> points = { Point2D<int>(0, 0), Point2D<int>(7, 0), Point2D<int>(10, 5), Point2D<int>(0, 9) };
    Polygone<int> poly(points);
    ZU zu(1, "Christine Yejin", poly);

    EXPECT_EQ(zu.getType(), "Zone Urbaine");
    EXPECT_EQ(zu.getSurface(), 62.5); // Surface calculée
    EXPECT_NEAR(zu.getSurfaceConstructible(), 8, 0.1); // Constructible estimée
}

TEST(ZA, AgriculturalZoneLimits) {
    std::vector<Point2D<int>> points = { Point2D<int>(0, 0), Point2D<int>(7, 0), Point2D<int>(10, 5), Point2D<int>(0, 9) };
    Polygone<int> poly(points);
    ZA za(1, "Bastien FELIX", poly);

    EXPECT_EQ(za.getType(), "Zone Agricole");
   
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
