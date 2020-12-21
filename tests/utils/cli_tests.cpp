#include <catch2/catch.hpp>
#include <utils/cli.hpp>

using Eigen::MatrixXd; 


TEST_CASE( "Quick check", "[main]" ) {
    REQUIRE( 2.0 == 2.0 );
}
