#define BOOST_TEST_MODULE Tests
#include <boost/test/unit_test.hpp>

#include "Tree.h"

BOOST_AUTO_TEST_CASE( my_test ) {
    Tree <int> * treeClaI = new Tree<int>();

    BOOST_CHECK_EQUAL(treeClaI->searchIntInputNum(treeClaI->getRoot(), searchVal), 13);
    BOOST_CHECK_EQUAL(treeCla->getSomeVal(treeCla->getRoot(), new int[2] {1, 1}), 0);

}
