//$$CDS-header$$

#ifndef CDSUNIT_SET_TYPE_SKIP_LIST_H
#define CDSUNIT_SET_TYPE_SKIP_LIST_H

#include "set2/set_type.h"

#include <cds/container/skip_list_set_hp.h>
#include <cds/container/skip_list_set_dhp.h>
#include <cds/container/skip_list_set_rcu.h>

#include "print_skip_list_stat.h"

namespace set2 {

    template <typename GC, typename T, typename Traits = cc::skip_list::traits >
    class SkipListSet : public cc::SkipListSet<GC, T, Traits>
    {
        typedef cc::SkipListSet<GC, T, Traits> base_class;
    public:
        template <typename Config>
        SkipListSet( Config const& /*cfg*/ )
        {}

        // for testing
        static CDS_CONSTEXPR bool const c_bExtractSupported = true;
        static CDS_CONSTEXPR bool const c_bLoadFactorDepended = false;
        static CDS_CONSTEXPR bool const c_bEraseExactKey = false;
    };

    struct tag_SkipListSet;

    template <typename Key, typename Val>
    struct set_type< tag_SkipListSet, Key, Val >: public set_type_base< Key, Val >
    {
        typedef set_type_base< Key, Val > base_class;
        typedef typename base_class::key_val key_val;
        typedef typename base_class::compare compare;
        typedef typename base_class::less less;
        typedef typename base_class::hash hash;

        class traits_SkipListSet_less_pascal: public cc::skip_list::make_traits <
                co::less< less >
                ,cc::skip_list::random_level_generator< cc::skip_list::turbo_pascal >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        {};
        typedef SkipListSet< cds::gc::HP, key_val, traits_SkipListSet_less_pascal > SkipListSet_hp_less_pascal;
        typedef SkipListSet< cds::gc::DHP, key_val, traits_SkipListSet_less_pascal > SkipListSet_dhp_less_pascal;
        typedef SkipListSet< rcu_gpi, key_val, traits_SkipListSet_less_pascal > SkipListSet_rcu_gpi_less_pascal;
        typedef SkipListSet< rcu_gpb, key_val, traits_SkipListSet_less_pascal > SkipListSet_rcu_gpb_less_pascal;
        typedef SkipListSet< rcu_gpt, key_val, traits_SkipListSet_less_pascal > SkipListSet_rcu_gpt_less_pascal;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef SkipListSet< rcu_shb, key_val, traits_SkipListSet_less_pascal > SkipListSet_rcu_shb_less_pascal;
        typedef SkipListSet< rcu_sht, key_val, traits_SkipListSet_less_pascal > SkipListSet_rcu_sht_less_pascal;
#endif

        class traits_SkipListSet_less_pascal_seqcst: public cc::skip_list::make_traits <
                co::less< less >
                ,cc::skip_list::random_level_generator< cc::skip_list::turbo_pascal >
                ,co::memory_model< co::v::sequential_consistent >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        {};
        typedef SkipListSet< cds::gc::HP, key_val, traits_SkipListSet_less_pascal_seqcst > SkipListSet_hp_less_pascal_seqcst;
        typedef SkipListSet< cds::gc::DHP, key_val, traits_SkipListSet_less_pascal_seqcst > SkipListSet_dhp_less_pascal_seqcst;
        typedef SkipListSet< rcu_gpi, key_val, traits_SkipListSet_less_pascal_seqcst > SkipListSet_rcu_gpi_less_pascal_seqcst;
        typedef SkipListSet< rcu_gpb, key_val, traits_SkipListSet_less_pascal_seqcst > SkipListSet_rcu_gpb_less_pascal_seqcst;
        typedef SkipListSet< rcu_gpt, key_val, traits_SkipListSet_less_pascal_seqcst > SkipListSet_rcu_gpt_less_pascal_seqcst;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef SkipListSet< rcu_shb, key_val, traits_SkipListSet_less_pascal_seqcst > SkipListSet_rcu_shb_less_pascal_seqcst;
        typedef SkipListSet< rcu_sht, key_val, traits_SkipListSet_less_pascal_seqcst > SkipListSet_rcu_sht_less_pascal_seqcst;
#endif

        class traits_SkipListSet_less_pascal_stat: public cc::skip_list::make_traits <
                co::less< less >
                ,cc::skip_list::random_level_generator< cc::skip_list::turbo_pascal >
                ,co::stat< cc::skip_list::stat<> >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        {};
        typedef SkipListSet< cds::gc::HP, key_val, traits_SkipListSet_less_pascal_stat > SkipListSet_hp_less_pascal_stat;
        typedef SkipListSet< cds::gc::DHP, key_val, traits_SkipListSet_less_pascal_stat > SkipListSet_dhp_less_pascal_stat;
        typedef SkipListSet< rcu_gpi, key_val, traits_SkipListSet_less_pascal_stat > SkipListSet_rcu_gpi_less_pascal_stat;
        typedef SkipListSet< rcu_gpb, key_val, traits_SkipListSet_less_pascal_stat > SkipListSet_rcu_gpb_less_pascal_stat;
        typedef SkipListSet< rcu_gpt, key_val, traits_SkipListSet_less_pascal_stat > SkipListSet_rcu_gpt_less_pascal_stat;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef SkipListSet< rcu_shb, key_val, traits_SkipListSet_less_pascal_stat > SkipListSet_rcu_shb_less_pascal_stat;
        typedef SkipListSet< rcu_sht, key_val, traits_SkipListSet_less_pascal_stat > SkipListSet_rcu_sht_less_pascal_stat;
#endif

        class traits_SkipListSet_cmp_pascal: public cc::skip_list::make_traits <
            co::compare< compare >
            ,cc::skip_list::random_level_generator< cc::skip_list::turbo_pascal >
            ,co::item_counter< cds::atomicity::item_counter >
        >::type
        {};
        typedef SkipListSet< cds::gc::HP, key_val, traits_SkipListSet_cmp_pascal > SkipListSet_hp_cmp_pascal;
        typedef SkipListSet< cds::gc::DHP, key_val, traits_SkipListSet_cmp_pascal > SkipListSet_dhp_cmp_pascal;
        typedef SkipListSet< rcu_gpi, key_val, traits_SkipListSet_cmp_pascal > SkipListSet_rcu_gpi_cmp_pascal;
        typedef SkipListSet< rcu_gpb, key_val, traits_SkipListSet_cmp_pascal > SkipListSet_rcu_gpb_cmp_pascal;
        typedef SkipListSet< rcu_gpt, key_val, traits_SkipListSet_cmp_pascal > SkipListSet_rcu_gpt_cmp_pascal;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef SkipListSet< rcu_shb, key_val, traits_SkipListSet_cmp_pascal > SkipListSet_rcu_shb_cmp_pascal;
        typedef SkipListSet< rcu_sht, key_val, traits_SkipListSet_cmp_pascal > SkipListSet_rcu_sht_cmp_pascal;
#endif

        class traits_SkipListSet_cmp_pascal_stat: public cc::skip_list::make_traits <
            co::compare< compare >
            ,cc::skip_list::random_level_generator< cc::skip_list::turbo_pascal >
            ,co::stat< cc::skip_list::stat<> >
            ,co::item_counter< cds::atomicity::item_counter >
        >::type
        {};
        typedef SkipListSet< cds::gc::HP, key_val, traits_SkipListSet_cmp_pascal_stat > SkipListSet_hp_cmp_pascal_stat;
        typedef SkipListSet< cds::gc::DHP, key_val, traits_SkipListSet_cmp_pascal_stat > SkipListSet_dhp_cmp_pascal_stat;
        typedef SkipListSet< rcu_gpi, key_val, traits_SkipListSet_cmp_pascal_stat > SkipListSet_rcu_gpi_cmp_pascal_stat;
        typedef SkipListSet< rcu_gpb, key_val, traits_SkipListSet_cmp_pascal_stat > SkipListSet_rcu_gpb_cmp_pascal_stat;
        typedef SkipListSet< rcu_gpt, key_val, traits_SkipListSet_cmp_pascal_stat > SkipListSet_rcu_gpt_cmp_pascal_stat;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef SkipListSet< rcu_shb, key_val, traits_SkipListSet_cmp_pascal_stat > SkipListSet_rcu_shb_cmp_pascal_stat;
        typedef SkipListSet< rcu_sht, key_val, traits_SkipListSet_cmp_pascal_stat > SkipListSet_rcu_sht_cmp_pascal_stat;
#endif

        class traits_SkipListSet_less_xorshift: public cc::skip_list::make_traits <
            co::less< less >
            ,cc::skip_list::random_level_generator< cc::skip_list::xorshift >
            ,co::item_counter< cds::atomicity::item_counter >
        >::type
        {};
        typedef SkipListSet< cds::gc::HP, key_val, traits_SkipListSet_less_xorshift > SkipListSet_hp_less_xorshift;
        typedef SkipListSet< cds::gc::DHP, key_val, traits_SkipListSet_less_xorshift > SkipListSet_dhp_less_xorshift;
        typedef SkipListSet< rcu_gpi, key_val, traits_SkipListSet_less_xorshift > SkipListSet_rcu_gpi_less_xorshift;
        typedef SkipListSet< rcu_gpb, key_val, traits_SkipListSet_less_xorshift > SkipListSet_rcu_gpb_less_xorshift;
        typedef SkipListSet< rcu_gpt, key_val, traits_SkipListSet_less_xorshift > SkipListSet_rcu_gpt_less_xorshift;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef SkipListSet< rcu_shb, key_val, traits_SkipListSet_less_xorshift > SkipListSet_rcu_shb_less_xorshift;
        typedef SkipListSet< rcu_sht, key_val, traits_SkipListSet_less_xorshift > SkipListSet_rcu_sht_less_xorshift;
#endif

        class traits_SkipListSet_less_xorshift_stat: public cc::skip_list::make_traits <
            co::less< less >
            ,cc::skip_list::random_level_generator< cc::skip_list::xorshift >
            ,co::stat< cc::skip_list::stat<> >
            ,co::item_counter< cds::atomicity::item_counter >
        >::type
        {};
        typedef SkipListSet< cds::gc::HP, key_val, traits_SkipListSet_less_xorshift_stat > SkipListSet_hp_less_xorshift_stat;
        typedef SkipListSet< cds::gc::DHP, key_val, traits_SkipListSet_less_xorshift_stat > SkipListSet_dhp_less_xorshift_stat;
        typedef SkipListSet< rcu_gpi, key_val, traits_SkipListSet_less_xorshift_stat > SkipListSet_rcu_gpi_less_xorshift_stat;
        typedef SkipListSet< rcu_gpb, key_val, traits_SkipListSet_less_xorshift_stat > SkipListSet_rcu_gpb_less_xorshift_stat;
        typedef SkipListSet< rcu_gpt, key_val, traits_SkipListSet_less_xorshift_stat > SkipListSet_rcu_gpt_less_xorshift_stat;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef SkipListSet< rcu_shb, key_val, traits_SkipListSet_less_xorshift_stat > SkipListSet_rcu_shb_less_xorshift_stat;
        typedef SkipListSet< rcu_sht, key_val, traits_SkipListSet_less_xorshift_stat > SkipListSet_rcu_sht_less_xorshift_stat;
#endif

        class traits_SkipListSet_cmp_xorshift: public cc::skip_list::make_traits <
            co::compare< compare >
            ,cc::skip_list::random_level_generator< cc::skip_list::xorshift >
            ,co::item_counter< cds::atomicity::item_counter >
        >::type
        {};
        typedef SkipListSet< cds::gc::HP, key_val, traits_SkipListSet_cmp_xorshift > SkipListSet_hp_cmp_xorshift;
        typedef SkipListSet< cds::gc::DHP, key_val, traits_SkipListSet_cmp_xorshift > SkipListSet_dhp_cmp_xorshift;
        typedef SkipListSet< rcu_gpi, key_val, traits_SkipListSet_cmp_xorshift > SkipListSet_rcu_gpi_cmp_xorshift;
        typedef SkipListSet< rcu_gpb, key_val, traits_SkipListSet_cmp_xorshift > SkipListSet_rcu_gpb_cmp_xorshift;
        typedef SkipListSet< rcu_gpt, key_val, traits_SkipListSet_cmp_xorshift > SkipListSet_rcu_gpt_cmp_xorshift;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef SkipListSet< rcu_shb, key_val, traits_SkipListSet_cmp_xorshift > SkipListSet_rcu_shb_cmp_xorshift;
        typedef SkipListSet< rcu_sht, key_val, traits_SkipListSet_cmp_xorshift > SkipListSet_rcu_sht_cmp_xorshift;
#endif

        class traits_SkipListSet_cmp_xorshift_stat: public cc::skip_list::make_traits <
            co::compare< compare >
            ,cc::skip_list::random_level_generator< cc::skip_list::xorshift >
            ,co::stat< cc::skip_list::stat<> >
            ,co::item_counter< cds::atomicity::item_counter >
        >::type
        {};
        typedef SkipListSet< cds::gc::HP, key_val, traits_SkipListSet_cmp_xorshift_stat > SkipListSet_hp_cmp_xorshift_stat;
        typedef SkipListSet< cds::gc::DHP, key_val, traits_SkipListSet_cmp_xorshift_stat > SkipListSet_dhp_cmp_xorshift_stat;
        typedef SkipListSet< rcu_gpi, key_val, traits_SkipListSet_cmp_xorshift_stat > SkipListSet_rcu_gpi_cmp_xorshift_stat;
        typedef SkipListSet< rcu_gpb, key_val, traits_SkipListSet_cmp_xorshift_stat > SkipListSet_rcu_gpb_cmp_xorshift_stat;
        typedef SkipListSet< rcu_gpt, key_val, traits_SkipListSet_cmp_xorshift_stat > SkipListSet_rcu_gpt_cmp_xorshift_stat;
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef SkipListSet< rcu_shb, key_val, traits_SkipListSet_cmp_xorshift_stat > SkipListSet_rcu_shb_cmp_xorshift_stat;
        typedef SkipListSet< rcu_sht, key_val, traits_SkipListSet_cmp_xorshift_stat > SkipListSet_rcu_sht_cmp_xorshift_stat;
#endif
    };

    template <typename GC, typename T, typename Traits>
    static inline void print_stat( SkipListSet<GC, T, Traits> const& s )
    {
        CPPUNIT_MSG( s.statistics() );
    }

} // namespace set2

#endif // #ifndef CDSUNIT_SET_TYPE_SKIP_LIST_H
