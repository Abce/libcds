//$$CDS-header$$

#include "map2/map_insdel_int.h"
#include "map2/map_type_skip_list.h"

#undef TEST_CASE
#define TEST_CASE(TAG, X)  void Map_InsDel_int::X() { run_test<typename map_type< TAG, key_type, value_type>::X>(); }
#include "map2/map_defs.h"

namespace map2 {
    CDSUNIT_DECLARE_SkipListMap
} // namespace map2
