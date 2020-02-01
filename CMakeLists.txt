cmake_minimum_required(VERSION 3.13)
project(OnlineJudge)

set(CMAKE_CXX_STANDARD 14)

include_directories("C++ Primer/GCC_4_7_0")
include_directories("C++ Primer/GCC_4_7_0/1")
include_directories("C++ Primer/GCC_4_7_0/12")
include_directories("C++ Primer/GCC_4_7_0/13")
include_directories("C++ Primer/GCC_4_7_0/14")
include_directories("C++ Primer/GCC_4_7_0/15")
include_directories("C++ Primer/GCC_4_7_0/16")
include_directories("C++ Primer/GCC_4_7_0/18")
include_directories("C++ Primer/GCC_4_7_0/19")
include_directories("C++ Primer/GCC_4_7_0/2")
include_directories("C++ Primer/GCC_4_7_0/6")
include_directories("C++ Primer/GCC_4_7_0/7")
include_directories("C++ Primer/VisualStudio2012")
include_directories("C++ Primer/VisualStudio2012/1")
include_directories("C++ Primer/VisualStudio2012/12")
include_directories("C++ Primer/VisualStudio2012/13")
include_directories("C++ Primer/VisualStudio2012/14")
include_directories("C++ Primer/VisualStudio2012/15")
include_directories("C++ Primer/VisualStudio2012/16")
include_directories("C++ Primer/VisualStudio2012/18")
include_directories("C++ Primer/VisualStudio2012/19")
include_directories("C++ Primer/VisualStudio2012/2")
include_directories("C++ Primer/VisualStudio2012/6")
include_directories("C++ Primer/VisualStudio2012/7")
include_directories(leetCode/algorithm)
include_directories(华为OJ/future_net)

add_executable(OnlineJudge
        "C++ Primer/GCC_4_7_0/1/add.cc"
        "C++ Primer/GCC_4_7_0/1/add_item.cc"
        "C++ Primer/GCC_4_7_0/1/add_item2.cc"
        "C++ Primer/GCC_4_7_0/1/avg_price.cc"
        "C++ Primer/GCC_4_7_0/1/for_ex.cc"
        "C++ Primer/GCC_4_7_0/1/forcount.cc"
        "C++ Primer/GCC_4_7_0/1/item_io.cc"
        "C++ Primer/GCC_4_7_0/1/main_only.cc"
        "C++ Primer/GCC_4_7_0/1/mysum.cc"
        "C++ Primer/GCC_4_7_0/1/occurs.cc"
        "C++ Primer/GCC_4_7_0/1/Sales_item.h"
        "C++ Primer/GCC_4_7_0/1/whilecount.cc"
        "C++ Primer/GCC_4_7_0/10/absInt.cc"
        "C++ Primer/GCC_4_7_0/10/accum.cc"
        "C++ Primer/GCC_4_7_0/10/accum4.cc"
        "C++ Primer/GCC_4_7_0/10/avg_price.cc"
        "C++ Primer/GCC_4_7_0/10/bind2.cc"
        "C++ Primer/GCC_4_7_0/10/elimDups.cc"
        "C++ Primer/GCC_4_7_0/10/equal.cc"
        "C++ Primer/GCC_4_7_0/10/equiv-istream-iter.cc"
        "C++ Primer/GCC_4_7_0/10/inserters.cc"
        "C++ Primer/GCC_4_7_0/10/iostream_iter.cc"
        "C++ Primer/GCC_4_7_0/10/lambda.cc"
        "C++ Primer/GCC_4_7_0/10/newcount-size.cc"
        "C++ Primer/GCC_4_7_0/10/ostreamIter2.cc"
        "C++ Primer/GCC_4_7_0/10/rcomma.cc"
        "C++ Primer/GCC_4_7_0/10/rev-iters.cc"
        "C++ Primer/GCC_4_7_0/10/reverse-iter.cc"
        "C++ Primer/GCC_4_7_0/10/reverse.cc"
        "C++ Primer/GCC_4_7_0/10/sortSI.cc"
        "C++ Primer/GCC_4_7_0/10/use-istream-iter.cc"
        "C++ Primer/GCC_4_7_0/10/use_find.cc"
        "C++ Primer/GCC_4_7_0/11/erasemap.cc"
        "C++ Primer/GCC_4_7_0/11/map1.cc"
        "C++ Primer/GCC_4_7_0/11/multimap.cc"
        "C++ Primer/GCC_4_7_0/11/pair.cc"
        "C++ Primer/GCC_4_7_0/11/restricted_count.cc"
        "C++ Primer/GCC_4_7_0/11/setOps.cc"
        "C++ Primer/GCC_4_7_0/11/unorderedWordCount.cc"
        "C++ Primer/GCC_4_7_0/11/wcEx.cc"
        "C++ Primer/GCC_4_7_0/11/word_count.cc"
        "C++ Primer/GCC_4_7_0/11/word_transform.cc"
        "C++ Primer/GCC_4_7_0/12/allocPtr.cc"
        "C++ Primer/GCC_4_7_0/12/allocSP.cc"
        "C++ Primer/GCC_4_7_0/12/Foo.h"
        "C++ Primer/GCC_4_7_0/12/oknew.cc"
        "C++ Primer/GCC_4_7_0/12/querymain.cc"
        "C++ Primer/GCC_4_7_0/12/QueryResult.h"
        "C++ Primer/GCC_4_7_0/12/release.cc"
        "C++ Primer/GCC_4_7_0/12/StrBlob.h"
        "C++ Primer/GCC_4_7_0/12/TextQuery.cc"
        "C++ Primer/GCC_4_7_0/12/TextQuery.h"
        "C++ Primer/GCC_4_7_0/12/unique.cc"
        "C++ Primer/GCC_4_7_0/12/UP.cc"
        "C++ Primer/GCC_4_7_0/12/usealloc.cc"
        "C++ Primer/GCC_4_7_0/12/usealloc2.cc"
        "C++ Primer/GCC_4_7_0/12/useBlob.cc"
        "C++ Primer/GCC_4_7_0/12/weak.cc"
        "C++ Primer/GCC_4_7_0/13/copyNoMove.cc"
        "C++ Primer/GCC_4_7_0/13/Folder.cc"
        "C++ Primer/GCC_4_7_0/13/Folder.h"
        "C++ Primer/GCC_4_7_0/13/FolderMain.cc"
        "C++ Primer/GCC_4_7_0/13/HasPtrUseCount.cc"
        "C++ Primer/GCC_4_7_0/13/HasPtrValueLike.cc"
        "C++ Primer/GCC_4_7_0/13/moveHP.cc"
        "C++ Primer/GCC_4_7_0/13/serial.cc"
        "C++ Primer/GCC_4_7_0/13/small_SI.h"
        "C++ Primer/GCC_4_7_0/13/StrFolder.cc"
        "C++ Primer/GCC_4_7_0/13/StrFolder.h"
        "C++ Primer/GCC_4_7_0/13/StrFolderMain.cc"
        "C++ Primer/GCC_4_7_0/13/String.cc"
        "C++ Primer/GCC_4_7_0/13/String.h"
        "C++ Primer/GCC_4_7_0/13/StrVec.cc"
        "C++ Primer/GCC_4_7_0/13/StrVec.h"
        "C++ Primer/GCC_4_7_0/13/substr.cc"
        "C++ Primer/GCC_4_7_0/13/useStrVec.cc"
        "C++ Primer/GCC_4_7_0/14/absInt.cc"
        "C++ Primer/GCC_4_7_0/14/add.cc"
        "C++ Primer/GCC_4_7_0/14/calc.cc"
        "C++ Primer/GCC_4_7_0/14/directcall.cc"
        "C++ Primer/GCC_4_7_0/14/fcnobj.cc"
        "C++ Primer/GCC_4_7_0/14/newcount-size.cc"
        "C++ Primer/GCC_4_7_0/14/readStr.cc"
        "C++ Primer/GCC_4_7_0/14/Sales_data.cc"
        "C++ Primer/GCC_4_7_0/14/Sales_data.h"
        "C++ Primer/GCC_4_7_0/15/and_orQueryTest.cc"
        "C++ Primer/GCC_4_7_0/15/andQueryTest.cc"
        "C++ Primer/GCC_4_7_0/15/Basket.cc"
        "C++ Primer/GCC_4_7_0/15/Basket.h"
        "C++ Primer/GCC_4_7_0/15/Basket_main.cc"
        "C++ Primer/GCC_4_7_0/15/get_print.cc"
        "C++ Primer/GCC_4_7_0/15/Query.cc"
        "C++ Primer/GCC_4_7_0/15/Query.h"
        "C++ Primer/GCC_4_7_0/15/Quote.cc"
        "C++ Primer/GCC_4_7_0/15/Quote.h"
        "C++ Primer/GCC_4_7_0/15/sample.cc"
        "C++ Primer/GCC_4_7_0/15/scope.cc"
        "C++ Primer/GCC_4_7_0/15/useQuote.cc"
        "C++ Primer/GCC_4_7_0/15/vecBasket.cc"
        "C++ Primer/GCC_4_7_0/15/virtualsNscope.cc"
        "C++ Primer/GCC_4_7_0/15/wordQueryTest.cc"
        "C++ Primer/GCC_4_7_0/16/array-parms4.cc"
        "C++ Primer/GCC_4_7_0/16/Array.cc"
        "C++ Primer/GCC_4_7_0/16/Blob.h"
        "C++ Primer/GCC_4_7_0/16/build.cc"
        "C++ Primer/GCC_4_7_0/16/compare.cc"
        "C++ Primer/GCC_4_7_0/16/compare.h"
        "C++ Primer/GCC_4_7_0/16/compareDef.cc"
        "C++ Primer/GCC_4_7_0/16/compareSpec.cc"
        "C++ Primer/GCC_4_7_0/16/debug.cc"
        "C++ Primer/GCC_4_7_0/16/debug_rep.h"
        "C++ Primer/GCC_4_7_0/16/DebugDelete.h"
        "C++ Primer/GCC_4_7_0/16/expansion.cc"
        "C++ Primer/GCC_4_7_0/16/flip.cc"
        "C++ Primer/GCC_4_7_0/16/multiset.cc"
        "C++ Primer/GCC_4_7_0/16/overSpec.cc"
        "C++ Primer/GCC_4_7_0/16/qm.cc"
        "C++ Primer/GCC_4_7_0/16/Sales_data.cc"
        "C++ Primer/GCC_4_7_0/16/Sales_data.h"
        "C++ Primer/GCC_4_7_0/16/SP.cc"
        "C++ Primer/GCC_4_7_0/16/special.cc"
        "C++ Primer/GCC_4_7_0/16/trail-ret.cc"
        "C++ Primer/GCC_4_7_0/16/typealias.cc"
        "C++ Primer/GCC_4_7_0/16/useBlob.cc"
        "C++ Primer/GCC_4_7_0/16/useChcking.cc"
        "C++ Primer/GCC_4_7_0/16/variadic.cc"
        "C++ Primer/GCC_4_7_0/16/variadic3.cc"
        "C++ Primer/GCC_4_7_0/16/Vec.h"
        "C++ Primer/GCC_4_7_0/16/Vecmain.cc"
        "C++ Primer/GCC_4_7_0/17/badgetc.cc"
        "C++ Primer/GCC_4_7_0/17/bits.cc"
        "C++ Primer/GCC_4_7_0/17/ccpgms.cc"
        "C++ Primer/GCC_4_7_0/17/findbook.cc"
        "C++ Primer/GCC_4_7_0/17/game.cc"
        "C++ Primer/GCC_4_7_0/17/getc.cc"
        "C++ Primer/GCC_4_7_0/17/getput.cc"
        "C++ Primer/GCC_4_7_0/17/manips.cc"
        "C++ Primer/GCC_4_7_0/17/manips11.cc"
        "C++ Primer/GCC_4_7_0/17/no-skipws.cc"
        "C++ Primer/GCC_4_7_0/17/normalInts.cc"
        "C++ Primer/GCC_4_7_0/17/phones.cc"
        "C++ Primer/GCC_4_7_0/17/phonesFinal.cc"
        "C++ Primer/GCC_4_7_0/17/point.cc"
        "C++ Primer/GCC_4_7_0/17/prec.cc"
        "C++ Primer/GCC_4_7_0/17/rand1.cc"
        "C++ Primer/GCC_4_7_0/17/rand2.cc"
        "C++ Primer/GCC_4_7_0/17/rand4.cc"
        "C++ Primer/GCC_4_7_0/17/rand6.cc"
        "C++ Primer/GCC_4_7_0/17/REerrs.cc"
        "C++ Primer/GCC_4_7_0/17/regex1.cc"
        "C++ Primer/GCC_4_7_0/17/sci_dec.cc"
        "C++ Primer/GCC_4_7_0/17/seed.cc"
        "C++ Primer/GCC_4_7_0/17/seek.cc"
        "C++ Primer/GCC_4_7_0/17/setw.cc"
        "C++ Primer/GCC_4_7_0/17/skipws.cc"
        "C++ Primer/GCC_4_7_0/17/subexpr.cc"
        "C++ Primer/GCC_4_7_0/17/tuple.cc"
        "C++ Primer/GCC_4_7_0/17/validatePhones.cc"
        "C++ Primer/GCC_4_7_0/17/zips.cc"
        "C++ Primer/GCC_4_7_0/18/Animal.cc"
        "C++ Primer/GCC_4_7_0/18/Animal.h"
        "C++ Primer/GCC_4_7_0/18/Animal_virtual_baseVers.h"
        "C++ Primer/GCC_4_7_0/18/book.cc"
        "C++ Primer/GCC_4_7_0/18/bookexcept.h"
        "C++ Primer/GCC_4_7_0/18/class.cc"
        "C++ Primer/GCC_4_7_0/18/ex-over.cc"
        "C++ Primer/GCC_4_7_0/18/inherit.cc"
        "C++ Primer/GCC_4_7_0/18/mi-scope.cc"
        "C++ Primer/GCC_4_7_0/18/over.cc"
        "C++ Primer/GCC_4_7_0/18/over2.cc"
        "C++ Primer/GCC_4_7_0/18/Sales_data.cc"
        "C++ Primer/GCC_4_7_0/18/spec.cc"
        "C++ Primer/GCC_4_7_0/18/usingDirective.cc"
        "C++ Primer/GCC_4_7_0/18/virt-inherit.cc"
        "C++ Primer/GCC_4_7_0/19/bitfields.cc"
        "C++ Primer/GCC_4_7_0/19/calc.cc"
        "C++ Primer/GCC_4_7_0/19/dyn_cast.cc"
        "C++ Primer/GCC_4_7_0/19/enum-match.cc"
        "C++ Primer/GCC_4_7_0/19/enum.cc"
        "C++ Primer/GCC_4_7_0/19/memFN-bind.cc"
        "C++ Primer/GCC_4_7_0/19/Screen.cc"
        "C++ Primer/GCC_4_7_0/19/Screen.h"
        "C++ Primer/GCC_4_7_0/19/TextQuery.h"
        "C++ Primer/GCC_4_7_0/19/tok2.cc"
        "C++ Primer/GCC_4_7_0/19/Token.h"
        "C++ Primer/GCC_4_7_0/19/typeid.cc"
        "C++ Primer/GCC_4_7_0/19/useScreen.cc"
        "C++ Primer/GCC_4_7_0/2/compounddecls.cc"
        "C++ Primer/GCC_4_7_0/2/convs.cc"
        "C++ Primer/GCC_4_7_0/2/dbl_ptr.cc"
        "C++ Primer/GCC_4_7_0/2/decl-ex.cc"
        "C++ Primer/GCC_4_7_0/2/escape.cc"
        "C++ Primer/GCC_4_7_0/2/inits.cc"
        "C++ Primer/GCC_4_7_0/2/literals.cc"
        "C++ Primer/GCC_4_7_0/2/ref-ex.cc"
        "C++ Primer/GCC_4_7_0/2/Sales_data.cc"
        "C++ Primer/GCC_4_7_0/2/Sales_data.h"
        "C++ Primer/GCC_4_7_0/2/scope_levels.cc"
        "C++ Primer/GCC_4_7_0/2/unsigned.cc"
        "C++ Primer/GCC_4_7_0/3/add_using.cc"
        "C++ Primer/GCC_4_7_0/3/arrayScores.cc"
        "C++ Primer/GCC_4_7_0/3/cctype.cc"
        "C++ Primer/GCC_4_7_0/3/char_repl.cc"
        "C++ Primer/GCC_4_7_0/3/cstring_hdr.cc"
        "C++ Primer/GCC_4_7_0/3/getline.cc"
        "C++ Primer/GCC_4_7_0/3/hexify.cc"
        "C++ Primer/GCC_4_7_0/3/multidim.cc"
        "C++ Primer/GCC_4_7_0/3/ptr_traversal2.cc"
        "C++ Primer/GCC_4_7_0/3/square.cc"
        "C++ Primer/GCC_4_7_0/3/strcompare.cc"
        "C++ Primer/GCC_4_7_0/3/string_add.cc"
        "C++ Primer/GCC_4_7_0/3/string_io.cc"
        "C++ Primer/GCC_4_7_0/3/string_io2.cc"
        "C++ Primer/GCC_4_7_0/3/string_size.cc"
        "C++ Primer/GCC_4_7_0/3/string_size2.cc"
        "C++ Primer/GCC_4_7_0/3/string_size3.cc"
        "C++ Primer/GCC_4_7_0/3/vec_decls.cc"
        "C++ Primer/GCC_4_7_0/3/vecScores.cc"
        "C++ Primer/GCC_4_7_0/3/vecStrings2.cc"
        "C++ Primer/GCC_4_7_0/3/vecSubs.cc"
        "C++ Primer/GCC_4_7_0/3/word_echo.cc"
        "C++ Primer/GCC_4_7_0/4/arith-ex.cc"
        "C++ Primer/GCC_4_7_0/4/arraysizeof.cc"
        "C++ Primer/GCC_4_7_0/4/cond.cc"
        "C++ Primer/GCC_4_7_0/4/incr.cc"
        "C++ Primer/GCC_4_7_0/4/int-div.cc"
        "C++ Primer/GCC_4_7_0/4/oofe.cc"
        "C++ Primer/GCC_4_7_0/4/overflow.cc"
        "C++ Primer/GCC_4_7_0/4/prec.cc"
        "C++ Primer/GCC_4_7_0/4/shift-prec.cc"
        "C++ Primer/GCC_4_7_0/4/sizeof_pgm.cc"
        "C++ Primer/GCC_4_7_0/4/unaryOps.cc"
        "C++ Primer/GCC_4_7_0/4/vec_init.cc"
        "C++ Primer/GCC_4_7_0/4/warn_dbltoint.cc"
        "C++ Primer/GCC_4_7_0/5/add_item2.cc"
        "C++ Primer/GCC_4_7_0/5/doWhile.cc"
        "C++ Primer/GCC_4_7_0/5/guess.cc"
        "C++ Primer/GCC_4_7_0/5/ifgrades.cc"
        "C++ Primer/GCC_4_7_0/5/othercnt.cc"
        "C++ Primer/GCC_4_7_0/5/rangefor.cc"
        "C++ Primer/GCC_4_7_0/5/vowels.cc"
        "C++ Primer/GCC_4_7_0/6/arrRet.cc"
        "C++ Primer/GCC_4_7_0/6/count-calls.cc"
        "C++ Primer/GCC_4_7_0/6/errMsg_initList.cc"
        "C++ Primer/GCC_4_7_0/6/fact.cc"
        "C++ Primer/GCC_4_7_0/6/fcnptrRet.cc"
        "C++ Primer/GCC_4_7_0/6/good_printmain.cc"
        "C++ Primer/GCC_4_7_0/6/inline_shorter.cc"
        "C++ Primer/GCC_4_7_0/6/LocalMath.cc"
        "C++ Primer/GCC_4_7_0/6/LocalMath.h"
        "C++ Primer/GCC_4_7_0/6/mainmath.cc"
        "C++ Primer/GCC_4_7_0/6/mainret.cc"
        "C++ Primer/GCC_4_7_0/6/make_plural.h"
        "C++ Primer/GCC_4_7_0/6/mk_plural.cc"
        "C++ Primer/GCC_4_7_0/6/printFcns.h"
        "C++ Primer/GCC_4_7_0/6/ref-fcn.cc"
        "C++ Primer/GCC_4_7_0/6/refparms.cc"
        "C++ Primer/GCC_4_7_0/6/refret-ex.cc"
        "C++ Primer/GCC_4_7_0/6/reset.cc"
        "C++ Primer/GCC_4_7_0/6/stl-arr-fcns.cc"
        "C++ Primer/GCC_4_7_0/6/use_mk_plural.cc"
        "C++ Primer/GCC_4_7_0/6/usefcnptr.cc"
        "C++ Primer/GCC_4_7_0/6/wdebug.cc"
        "C++ Primer/GCC_4_7_0/7/Account.cc"
        "C++ Primer/GCC_4_7_0/7/Account.h"
        "C++ Primer/GCC_4_7_0/7/add_item.cc"
        "C++ Primer/GCC_4_7_0/7/avg_price.cc"
        "C++ Primer/GCC_4_7_0/7/Debug.cc"
        "C++ Primer/GCC_4_7_0/7/Debug.h"
        "C++ Primer/GCC_4_7_0/7/Sales_data.cc"
        "C++ Primer/GCC_4_7_0/7/Sales_data.h"
        "C++ Primer/GCC_4_7_0/7/Screen.h"
        "C++ Primer/GCC_4_7_0/7/useAccount.cc"
        "C++ Primer/GCC_4_7_0/7/useDebug.cc"
        "C++ Primer/GCC_4_7_0/7/useScreen.cc"
        "C++ Primer/GCC_4_7_0/7/WindowMgr.h"
        "C++ Primer/GCC_4_7_0/8/add_item.cc"
        "C++ Primer/GCC_4_7_0/8/add_itemV2.cc"
        "C++ Primer/GCC_4_7_0/8/buf.cc"
        "C++ Primer/GCC_4_7_0/8/clearIO.cc"
        "C++ Primer/GCC_4_7_0/8/fileIO.cc"
        "C++ Primer/GCC_4_7_0/8/sstream.cc"
        "C++ Primer/GCC_4_7_0/9/capacity.cc"
        "C++ Primer/GCC_4_7_0/9/erase1.cc"
        "C++ Primer/GCC_4_7_0/9/erase2.cc"
        "C++ Primer/GCC_4_7_0/9/find-str.cc"
        "C++ Primer/GCC_4_7_0/9/find_ops.cc"
        "C++ Primer/GCC_4_7_0/9/refreshIter.cc"
        "C++ Primer/GCC_4_7_0/9/stack.cc"
        "C++ Primer/GCC_4_7_0/9/str_assignOps.cc"
        "C++ Primer/GCC_4_7_0/9/substr.cc"
        "C++ Primer/GCC_4_7_0/9/useConvs.cc"
        "C++ Primer/GCC_4_7_0/Version_test.h"
        "C++ Primer/VisualStudio2012/1/add.cpp"
        "C++ Primer/VisualStudio2012/1/add_item.cpp"
        "C++ Primer/VisualStudio2012/1/add_item2.cpp"
        "C++ Primer/VisualStudio2012/1/avg_price.cpp"
        "C++ Primer/VisualStudio2012/1/for_ex.cpp"
        "C++ Primer/VisualStudio2012/1/forcount.cpp"
        "C++ Primer/VisualStudio2012/1/item_io.cpp"
        "C++ Primer/VisualStudio2012/1/main_only.cpp"
        "C++ Primer/VisualStudio2012/1/mysum.cpp"
        "C++ Primer/VisualStudio2012/1/occurs.cpp"
        "C++ Primer/VisualStudio2012/1/Sales_item.h"
        "C++ Primer/VisualStudio2012/1/whilecount.cpp"
        "C++ Primer/VisualStudio2012/10/absInt.cpp"
        "C++ Primer/VisualStudio2012/10/accum.cpp"
        "C++ Primer/VisualStudio2012/10/accum4.cpp"
        "C++ Primer/VisualStudio2012/10/avg_price.cpp"
        "C++ Primer/VisualStudio2012/10/bind2.cpp"
        "C++ Primer/VisualStudio2012/10/elimDups.cpp"
        "C++ Primer/VisualStudio2012/10/equal.cpp"
        "C++ Primer/VisualStudio2012/10/equiv-istream-iter.cpp"
        "C++ Primer/VisualStudio2012/10/inserters.cpp"
        "C++ Primer/VisualStudio2012/10/iostream_iter.cpp"
        "C++ Primer/VisualStudio2012/10/lambda.cpp"
        "C++ Primer/VisualStudio2012/10/newcount-size.cpp"
        "C++ Primer/VisualStudio2012/10/ostreamIter2.cpp"
        "C++ Primer/VisualStudio2012/10/rcomma.cpp"
        "C++ Primer/VisualStudio2012/10/rev-iters.cpp"
        "C++ Primer/VisualStudio2012/10/reverse-iter.cpp"
        "C++ Primer/VisualStudio2012/10/reverse.cpp"
        "C++ Primer/VisualStudio2012/10/sortSI.cpp"
        "C++ Primer/VisualStudio2012/10/use-istream-iter.cpp"
        "C++ Primer/VisualStudio2012/10/use_find.cpp"
        "C++ Primer/VisualStudio2012/11/erasemap.cpp"
        "C++ Primer/VisualStudio2012/11/map1.cpp"
        "C++ Primer/VisualStudio2012/11/multimap.cpp"
        "C++ Primer/VisualStudio2012/11/pair.cpp"
        "C++ Primer/VisualStudio2012/11/restricted_count.cpp"
        "C++ Primer/VisualStudio2012/11/setOps.cpp"
        "C++ Primer/VisualStudio2012/11/unorderedWordCount.cpp"
        "C++ Primer/VisualStudio2012/11/wcEx.cpp"
        "C++ Primer/VisualStudio2012/11/word_count.cpp"
        "C++ Primer/VisualStudio2012/11/word_transform.cpp"
        "C++ Primer/VisualStudio2012/12/allocPtr.cpp"
        "C++ Primer/VisualStudio2012/12/allocSP.cpp"
        "C++ Primer/VisualStudio2012/12/Foo.h"
        "C++ Primer/VisualStudio2012/12/oknew.cpp"
        "C++ Primer/VisualStudio2012/12/querymain.cpp"
        "C++ Primer/VisualStudio2012/12/QueryResult.h"
        "C++ Primer/VisualStudio2012/12/release.cpp"
        "C++ Primer/VisualStudio2012/12/StrBlob.h"
        "C++ Primer/VisualStudio2012/12/TextQuery.cpp"
        "C++ Primer/VisualStudio2012/12/TextQuery.h"
        "C++ Primer/VisualStudio2012/12/unique.cpp"
        "C++ Primer/VisualStudio2012/12/UP.cpp"
        "C++ Primer/VisualStudio2012/12/usealloc.cpp"
        "C++ Primer/VisualStudio2012/12/usealloc2.cpp"
        "C++ Primer/VisualStudio2012/12/useBlob.cpp"
        "C++ Primer/VisualStudio2012/12/weak.cpp"
        "C++ Primer/VisualStudio2012/13/copyNoMove.cpp"
        "C++ Primer/VisualStudio2012/13/Folder.cpp"
        "C++ Primer/VisualStudio2012/13/Folder.h"
        "C++ Primer/VisualStudio2012/13/FolderMain.cpp"
        "C++ Primer/VisualStudio2012/13/HasPtrUseCount.cpp"
        "C++ Primer/VisualStudio2012/13/HasPtrValueLike.cpp"
        "C++ Primer/VisualStudio2012/13/moveHP.cpp"
        "C++ Primer/VisualStudio2012/13/serial.cpp"
        "C++ Primer/VisualStudio2012/13/small_SI.h"
        "C++ Primer/VisualStudio2012/13/StrFolder.cpp"
        "C++ Primer/VisualStudio2012/13/StrFolder.h"
        "C++ Primer/VisualStudio2012/13/StrFolderMain.cpp"
        "C++ Primer/VisualStudio2012/13/String.cpp"
        "C++ Primer/VisualStudio2012/13/String.h"
        "C++ Primer/VisualStudio2012/13/StrVec.cpp"
        "C++ Primer/VisualStudio2012/13/StrVec.h"
        "C++ Primer/VisualStudio2012/13/substr.cpp"
        "C++ Primer/VisualStudio2012/13/useStrVec.cpp"
        "C++ Primer/VisualStudio2012/14/absInt.cpp"
        "C++ Primer/VisualStudio2012/14/add.cpp"
        "C++ Primer/VisualStudio2012/14/calc.cpp"
        "C++ Primer/VisualStudio2012/14/directcall.cpp"
        "C++ Primer/VisualStudio2012/14/fcnobj.cpp"
        "C++ Primer/VisualStudio2012/14/newcount-size.cpp"
        "C++ Primer/VisualStudio2012/14/readStr.cpp"
        "C++ Primer/VisualStudio2012/14/Sales_data.cpp"
        "C++ Primer/VisualStudio2012/14/Sales_data.h"
        "C++ Primer/VisualStudio2012/15/and_orQueryTest.cpp"
        "C++ Primer/VisualStudio2012/15/andQueryTest.cpp"
        "C++ Primer/VisualStudio2012/15/Basket.cpp"
        "C++ Primer/VisualStudio2012/15/Basket.h"
        "C++ Primer/VisualStudio2012/15/Basket_main.cpp"
        "C++ Primer/VisualStudio2012/15/get_print.cpp"
        "C++ Primer/VisualStudio2012/15/Query.cpp"
        "C++ Primer/VisualStudio2012/15/Query.h"
        "C++ Primer/VisualStudio2012/15/Quote.cpp"
        "C++ Primer/VisualStudio2012/15/Quote.h"
        "C++ Primer/VisualStudio2012/15/sample.cpp"
        "C++ Primer/VisualStudio2012/15/scope.cpp"
        "C++ Primer/VisualStudio2012/15/useQuote.cpp"
        "C++ Primer/VisualStudio2012/15/vecBasket.cpp"
        "C++ Primer/VisualStudio2012/15/virtualsNscope.cpp"
        "C++ Primer/VisualStudio2012/15/wordQueryTest.cpp"
        "C++ Primer/VisualStudio2012/16/array-parms4.cpp"
        "C++ Primer/VisualStudio2012/16/Array.cpp"
        "C++ Primer/VisualStudio2012/16/Blob.h"
        "C++ Primer/VisualStudio2012/16/build.cpp"
        "C++ Primer/VisualStudio2012/16/compare.cpp"
        "C++ Primer/VisualStudio2012/16/compare.h"
        "C++ Primer/VisualStudio2012/16/compareDef.cpp"
        "C++ Primer/VisualStudio2012/16/compareSpec.cpp"
        "C++ Primer/VisualStudio2012/16/debug.cpp"
        "C++ Primer/VisualStudio2012/16/debug_rep.h"
        "C++ Primer/VisualStudio2012/16/DebugDelete.h"
        "C++ Primer/VisualStudio2012/16/expansion.cpp"
        "C++ Primer/VisualStudio2012/16/flip.cpp"
        "C++ Primer/VisualStudio2012/16/multiset.cpp"
        "C++ Primer/VisualStudio2012/16/overSpec.cpp"
        "C++ Primer/VisualStudio2012/16/qm.cpp"
        "C++ Primer/VisualStudio2012/16/Sales_data.cpp"
        "C++ Primer/VisualStudio2012/16/Sales_data.h"
        "C++ Primer/VisualStudio2012/16/SP.cpp"
        "C++ Primer/VisualStudio2012/16/special.cpp"
        "C++ Primer/VisualStudio2012/16/trail-ret.cpp"
        "C++ Primer/VisualStudio2012/16/typealias.cpp"
        "C++ Primer/VisualStudio2012/16/useBlob.cpp"
        "C++ Primer/VisualStudio2012/16/useChcking.cpp"
        "C++ Primer/VisualStudio2012/16/variadic.cpp"
        "C++ Primer/VisualStudio2012/16/variadic3.cpp"
        "C++ Primer/VisualStudio2012/16/Vec.h"
        "C++ Primer/VisualStudio2012/16/Vecmain.cpp"
        "C++ Primer/VisualStudio2012/17/badgetc.cpp"
        "C++ Primer/VisualStudio2012/17/bits.cpp"
        "C++ Primer/VisualStudio2012/17/ccpgms.cpp"
        "C++ Primer/VisualStudio2012/17/findbook.cpp"
        "C++ Primer/VisualStudio2012/17/game.cpp"
        "C++ Primer/VisualStudio2012/17/getc.cpp"
        "C++ Primer/VisualStudio2012/17/getput.cpp"
        "C++ Primer/VisualStudio2012/17/manips.cpp"
        "C++ Primer/VisualStudio2012/17/manips11.cpp"
        "C++ Primer/VisualStudio2012/17/no-skipws.cpp"
        "C++ Primer/VisualStudio2012/17/normalInts.cpp"
        "C++ Primer/VisualStudio2012/17/phones.cpp"
        "C++ Primer/VisualStudio2012/17/phonesFinal.cpp"
        "C++ Primer/VisualStudio2012/17/point.cpp"
        "C++ Primer/VisualStudio2012/17/prec.cpp"
        "C++ Primer/VisualStudio2012/17/rand1.cpp"
        "C++ Primer/VisualStudio2012/17/rand2.cpp"
        "C++ Primer/VisualStudio2012/17/rand4.cpp"
        "C++ Primer/VisualStudio2012/17/rand6.cpp"
        "C++ Primer/VisualStudio2012/17/REerrs.cpp"
        "C++ Primer/VisualStudio2012/17/regex1.cpp"
        "C++ Primer/VisualStudio2012/17/sci_dec.cpp"
        "C++ Primer/VisualStudio2012/17/seed.cpp"
        "C++ Primer/VisualStudio2012/17/seek.cpp"
        "C++ Primer/VisualStudio2012/17/setw.cpp"
        "C++ Primer/VisualStudio2012/17/skipws.cpp"
        "C++ Primer/VisualStudio2012/17/subexpr.cpp"
        "C++ Primer/VisualStudio2012/17/tuple.cpp"
        "C++ Primer/VisualStudio2012/17/validatePhones.cpp"
        "C++ Primer/VisualStudio2012/17/zips.cpp"
        "C++ Primer/VisualStudio2012/18/Animal.cpp"
        "C++ Primer/VisualStudio2012/18/Animal.h"
        "C++ Primer/VisualStudio2012/18/Animal_virtual_baseVers.h"
        "C++ Primer/VisualStudio2012/18/book.cpp"
        "C++ Primer/VisualStudio2012/18/bookexcept.h"
        "C++ Primer/VisualStudio2012/18/class.cpp"
        "C++ Primer/VisualStudio2012/18/ex-over.cpp"
        "C++ Primer/VisualStudio2012/18/inherit.cpp"
        "C++ Primer/VisualStudio2012/18/mi-scope.cpp"
        "C++ Primer/VisualStudio2012/18/over.cpp"
        "C++ Primer/VisualStudio2012/18/over2.cpp"
        "C++ Primer/VisualStudio2012/18/Sales_data.cpp"
        "C++ Primer/VisualStudio2012/18/spec.cpp"
        "C++ Primer/VisualStudio2012/18/usingDirective.cpp"
        "C++ Primer/VisualStudio2012/18/virt-inherit.cpp"
        "C++ Primer/VisualStudio2012/19/ADVScreen.h"
        "C++ Primer/VisualStudio2012/19/bitfields.cpp"
        "C++ Primer/VisualStudio2012/19/calc.cpp"
        "C++ Primer/VisualStudio2012/19/dyn_cast.cpp"
        "C++ Primer/VisualStudio2012/19/enum-match.cpp"
        "C++ Primer/VisualStudio2012/19/enum.cpp"
        "C++ Primer/VisualStudio2012/19/memFN-bind.cpp"
        "C++ Primer/VisualStudio2012/19/Screen.cpp"
        "C++ Primer/VisualStudio2012/19/Screen.h"
        "C++ Primer/VisualStudio2012/19/TextQuery.h"
        "C++ Primer/VisualStudio2012/19/tok2.cpp"
        "C++ Primer/VisualStudio2012/19/Token.h"
        "C++ Primer/VisualStudio2012/19/typeid.cpp"
        "C++ Primer/VisualStudio2012/19/useScreen.cpp"
        "C++ Primer/VisualStudio2012/2/compounddecls.cpp"
        "C++ Primer/VisualStudio2012/2/convs.cpp"
        "C++ Primer/VisualStudio2012/2/dbl_ptr.cpp"
        "C++ Primer/VisualStudio2012/2/decl-ex.cpp"
        "C++ Primer/VisualStudio2012/2/escape.cpp"
        "C++ Primer/VisualStudio2012/2/inits.cpp"
        "C++ Primer/VisualStudio2012/2/literals.cpp"
        "C++ Primer/VisualStudio2012/2/ref-ex.cpp"
        "C++ Primer/VisualStudio2012/2/Sales_data.cpp"
        "C++ Primer/VisualStudio2012/2/Sales_data.h"
        "C++ Primer/VisualStudio2012/2/scope_levels.cpp"
        "C++ Primer/VisualStudio2012/2/unsigned.cpp"
        "C++ Primer/VisualStudio2012/3/add_using.cpp"
        "C++ Primer/VisualStudio2012/3/arrayScores.cpp"
        "C++ Primer/VisualStudio2012/3/cctype.cpp"
        "C++ Primer/VisualStudio2012/3/char_repl.cpp"
        "C++ Primer/VisualStudio2012/3/cstring_hdr.cpp"
        "C++ Primer/VisualStudio2012/3/getline.cpp"
        "C++ Primer/VisualStudio2012/3/hexify.cpp"
        "C++ Primer/VisualStudio2012/3/multidim.cpp"
        "C++ Primer/VisualStudio2012/3/ptr_traversal2.cpp"
        "C++ Primer/VisualStudio2012/3/square.cpp"
        "C++ Primer/VisualStudio2012/3/strcompare.cpp"
        "C++ Primer/VisualStudio2012/3/string_add.cpp"
        "C++ Primer/VisualStudio2012/3/string_io.cpp"
        "C++ Primer/VisualStudio2012/3/string_io2.cpp"
        "C++ Primer/VisualStudio2012/3/string_size.cpp"
        "C++ Primer/VisualStudio2012/3/string_size2.cpp"
        "C++ Primer/VisualStudio2012/3/string_size3.cpp"
        "C++ Primer/VisualStudio2012/3/vec_decls.cpp"
        "C++ Primer/VisualStudio2012/3/vecScores.cpp"
        "C++ Primer/VisualStudio2012/3/vecStrings2.cpp"
        "C++ Primer/VisualStudio2012/3/vecSubs.cpp"
        "C++ Primer/VisualStudio2012/3/word_echo.cpp"
        "C++ Primer/VisualStudio2012/4/arith-ex.cpp"
        "C++ Primer/VisualStudio2012/4/arraysizeof.cpp"
        "C++ Primer/VisualStudio2012/4/cond.cpp"
        "C++ Primer/VisualStudio2012/4/incr.cpp"
        "C++ Primer/VisualStudio2012/4/int-div.cpp"
        "C++ Primer/VisualStudio2012/4/oofe.cpp"
        "C++ Primer/VisualStudio2012/4/overflow.cpp"
        "C++ Primer/VisualStudio2012/4/prec.cpp"
        "C++ Primer/VisualStudio2012/4/shift-prec.cpp"
        "C++ Primer/VisualStudio2012/4/sizeof_pgm.cpp"
        "C++ Primer/VisualStudio2012/4/unaryOps.cpp"
        "C++ Primer/VisualStudio2012/4/vec_init.cpp"
        "C++ Primer/VisualStudio2012/4/warn_dbltoint.cpp"
        "C++ Primer/VisualStudio2012/5/add_item2.cpp"
        "C++ Primer/VisualStudio2012/5/doWhile.cpp"
        "C++ Primer/VisualStudio2012/5/guess.cpp"
        "C++ Primer/VisualStudio2012/5/ifgrades.cpp"
        "C++ Primer/VisualStudio2012/5/othercnt.cpp"
        "C++ Primer/VisualStudio2012/5/rangefor.cpp"
        "C++ Primer/VisualStudio2012/5/vowels.cpp"
        "C++ Primer/VisualStudio2012/6/arrRet.cpp"
        "C++ Primer/VisualStudio2012/6/count-calls.cpp"
        "C++ Primer/VisualStudio2012/6/errMsg_initList.cpp"
        "C++ Primer/VisualStudio2012/6/fact.cpp"
        "C++ Primer/VisualStudio2012/6/fcnptrRet.cpp"
        "C++ Primer/VisualStudio2012/6/good_printmain.cpp"
        "C++ Primer/VisualStudio2012/6/inline_shorter.cpp"
        "C++ Primer/VisualStudio2012/6/LocalMath.cpp"
        "C++ Primer/VisualStudio2012/6/LocalMath.h"
        "C++ Primer/VisualStudio2012/6/mainmath.cpp"
        "C++ Primer/VisualStudio2012/6/mainret.cpp"
        "C++ Primer/VisualStudio2012/6/make_plural.h"
        "C++ Primer/VisualStudio2012/6/mk_plural.cpp"
        "C++ Primer/VisualStudio2012/6/printFcns.h"
        "C++ Primer/VisualStudio2012/6/ref-fcn.cpp"
        "C++ Primer/VisualStudio2012/6/refparms.cpp"
        "C++ Primer/VisualStudio2012/6/refret-ex.cpp"
        "C++ Primer/VisualStudio2012/6/reset.cpp"
        "C++ Primer/VisualStudio2012/6/stl-arr-fcns.cpp"
        "C++ Primer/VisualStudio2012/6/use_mk_plural.cpp"
        "C++ Primer/VisualStudio2012/6/usefcnptr.cpp"
        "C++ Primer/VisualStudio2012/6/wdebug.cpp"
        "C++ Primer/VisualStudio2012/7/Account.cpp"
        "C++ Primer/VisualStudio2012/7/Account.h"
        "C++ Primer/VisualStudio2012/7/add_item.cpp"
        "C++ Primer/VisualStudio2012/7/avg_price.cpp"
        "C++ Primer/VisualStudio2012/7/Debug.cpp"
        "C++ Primer/VisualStudio2012/7/Debug.h"
        "C++ Primer/VisualStudio2012/7/Sales_data.cpp"
        "C++ Primer/VisualStudio2012/7/Sales_data.h"
        "C++ Primer/VisualStudio2012/7/Screen.h"
        "C++ Primer/VisualStudio2012/7/useAccount.cpp"
        "C++ Primer/VisualStudio2012/7/useDebug.cpp"
        "C++ Primer/VisualStudio2012/7/useScreen.cpp"
        "C++ Primer/VisualStudio2012/7/WindowMgr.h"
        "C++ Primer/VisualStudio2012/8/add_item.cpp"
        "C++ Primer/VisualStudio2012/8/add_itemV2.cpp"
        "C++ Primer/VisualStudio2012/8/buf.cpp"
        "C++ Primer/VisualStudio2012/8/clearIO.cpp"
        "C++ Primer/VisualStudio2012/8/fileIO.cpp"
        "C++ Primer/VisualStudio2012/8/sstream.cpp"
        "C++ Primer/VisualStudio2012/9/capacity.cpp"
        "C++ Primer/VisualStudio2012/9/erase1.cpp"
        "C++ Primer/VisualStudio2012/9/erase2.cpp"
        "C++ Primer/VisualStudio2012/9/find-str.cpp"
        "C++ Primer/VisualStudio2012/9/find_ops.cpp"
        "C++ Primer/VisualStudio2012/9/refreshIter.cpp"
        "C++ Primer/VisualStudio2012/9/stack.cpp"
        "C++ Primer/VisualStudio2012/9/str_assignOps.cpp"
        "C++ Primer/VisualStudio2012/9/substr.cpp"
        "C++ Primer/VisualStudio2012/9/useConvs.cpp"
        "C++ Primer/VisualStudio2012/Version_test.h"
        leetCode/algorithm/_c207.h
        leetCode/algorithm/_c208.h
        leetCode/algorithm/_c209.h
        leetCode/algorithm/_c210.h
        leetCode/archive/_C001.cpp
        leetCode/archive/_C002.cpp
        leetCode/archive/_C003.cpp
        leetCode/archive/_C004.cpp
        leetCode/archive/_C005.cpp
        leetCode/archive/_C006.cpp
        leetCode/archive/_C007.cpp
        leetCode/archive/_C008.cpp
        leetCode/archive/_C009.cpp
        leetCode/archive/_C010.cpp
        leetCode/archive/_C011.cpp
        leetCode/archive/_C012.cpp
        leetCode/archive/_C013.cpp
        leetCode/archive/_C014.cpp
        leetCode/archive/_C015.cpp
        leetCode/archive/_C016.cpp
        leetCode/archive/_C017.cpp
        leetCode/archive/_C018.cpp
        leetCode/archive/_C019.cpp
        leetCode/archive/_C020.cpp
        leetCode/archive/_C021.cpp
        leetCode/archive/_C022.cpp
        leetCode/archive/_C023.cpp
        leetCode/archive/_C024.cpp
        leetCode/archive/_C025.cpp
        leetCode/archive/_C026.cpp
        leetCode/archive/_C027.cpp
        leetCode/archive/_C028.cpp
        leetCode/archive/_C029.cpp
        leetCode/archive/_C030.cpp
        leetCode/archive/_C031.cpp
        leetCode/archive/_C032.cpp
        leetCode/archive/_C033.cpp
        leetCode/archive/_C034.cpp
        leetCode/archive/_C035.cpp
        leetCode/archive/_C036.cpp
        leetCode/archive/_C037.cpp
        leetCode/archive/_C038.cpp
        leetCode/archive/_C039.cpp
        leetCode/archive/_C040.cpp
        leetCode/archive/_C041.cpp
        leetCode/archive/_C042.cpp
        leetCode/archive/_C043.cpp
        leetCode/archive/_C044.cpp
        leetCode/archive/_C045.cpp
        leetCode/archive/_C046.cpp
        leetCode/archive/_C047.cpp
        leetCode/archive/_C048.cpp
        leetCode/archive/_C049.cpp
        leetCode/archive/_C050.cpp
        leetCode/archive/_C051.cpp
        leetCode/archive/_C052.cpp
        leetCode/archive/_C053.cpp
        leetCode/archive/_C054.cpp
        leetCode/archive/_C055.cpp
        leetCode/archive/_C056.cpp
        leetCode/archive/_C057.cpp
        leetCode/archive/_C058.cpp
        leetCode/archive/_C059.cpp
        leetCode/archive/_C060.cpp
        leetCode/archive/_C061.cpp
        leetCode/archive/_C062.cpp
        leetCode/archive/_C063.cpp
        leetCode/archive/_C064.cpp
        leetCode/archive/_C065.cpp
        leetCode/archive/_C066.cpp
        leetCode/archive/_C067.cpp
        leetCode/archive/_C068.cpp
        leetCode/archive/_C069.cpp
        leetCode/archive/_C070.cpp
        leetCode/archive/_C071.cpp
        leetCode/archive/_C072.cpp
        leetCode/archive/_C073.cpp
        leetCode/archive/_C074.cpp
        leetCode/archive/_C075.cpp
        leetCode/archive/_C076.cpp
        leetCode/archive/_C077.cpp
        leetCode/archive/_C078.cpp
        leetCode/archive/_C079.cpp
        leetCode/archive/_C080.cpp
        leetCode/archive/_C081.cpp
        leetCode/archive/_C082.cpp
        leetCode/archive/_C083.cpp
        leetCode/archive/_C084.cpp
        leetCode/archive/_C085.cpp
        leetCode/archive/_C086.cpp
        leetCode/archive/_C087.cpp
        leetCode/archive/_C088.cpp
        leetCode/archive/_C089.cpp
        leetCode/archive/_C090.cpp
        leetCode/archive/_C091.cpp
        leetCode/archive/_C092.cpp
        leetCode/archive/_C093.cpp
        leetCode/archive/_C094.cpp
        leetCode/archive/_C095.cpp
        leetCode/archive/_C096.cpp
        leetCode/archive/_C097.cpp
        leetCode/archive/_C098.cpp
        leetCode/archive/_C099.cpp
        leetCode/archive/_C100.cpp
        leetCode/archive/_C101.cpp
        leetCode/archive/_C102.cpp
        leetCode/archive/_C103.cpp
        leetCode/archive/_C104.cpp
        leetCode/archive/_C105.cpp
        leetCode/archive/_C106.cpp
        leetCode/archive/_C107.cpp
        leetCode/archive/_C108.cpp
        leetCode/archive/_C109.cpp
        leetCode/archive/_C110.cpp
        leetCode/archive/_C111.cpp
        leetCode/archive/_C112.cpp
        leetCode/archive/_C113.cpp
        leetCode/archive/_C114.cpp
        leetCode/archive/_C115.cpp
        leetCode/archive/_C116.cpp
        leetCode/archive/_C117.cpp
        leetCode/archive/_C118.cpp
        leetCode/archive/_C119.cpp
        leetCode/archive/_C120.cpp
        leetCode/archive/_C121.cpp
        leetCode/archive/_C122.cpp
        leetCode/archive/_C123.cpp
        leetCode/archive/_C124.cpp
        leetCode/archive/_C125.cpp
        leetCode/archive/_C126.cpp
        leetCode/archive/_C127.cpp
        leetCode/archive/_C128.cpp
        leetCode/archive/_C129.cpp
        leetCode/archive/_C130.cpp
        leetCode/archive/_C131.cpp
        leetCode/archive/_C132.cpp
        leetCode/archive/_C133.cpp
        leetCode/archive/_C134.cpp
        leetCode/archive/_C135.cpp
        leetCode/archive/_C136.cpp
        leetCode/archive/_C137.cpp
        leetCode/archive/_C138.cpp
        leetCode/archive/_C139.cpp
        leetCode/archive/_C140.cpp
        leetCode/archive/_C141.cpp
        leetCode/archive/_C142.cpp
        leetCode/archive/_C143.cpp
        leetCode/archive/_C144.cpp
        leetCode/archive/_C145.cpp
        leetCode/archive/_C146.cpp
        leetCode/archive/_C147.cpp
        leetCode/archive/_C148.cpp
        leetCode/archive/_C149.cpp
        leetCode/archive/_C150.cpp
        leetCode/archive/_C151.cpp
        leetCode/archive/_C152.cpp
        leetCode/archive/_C153.cpp
        leetCode/archive/_C154.cpp
        leetCode/archive/_C155.cpp
        leetCode/archive/_C160.cpp
        leetCode/archive/_C162.cpp
        leetCode/archive/_C164.cpp
        leetCode/archive/_C165.cpp
        leetCode/archive/_C166.cpp
        leetCode/archive/_C167.cpp
        leetCode/archive/_C168.cpp
        leetCode/archive/_C169.cpp
        leetCode/archive/_C171.cpp
        leetCode/archive/_C172.cpp
        leetCode/archive/_C173.cpp
        leetCode/archive/_C174.cpp
        leetCode/archive/_C179.cpp
        leetCode/archive/_C187.cpp
        leetCode/archive/_C188.cpp
        leetCode/archive/_C189.cpp
        leetCode/archive/_C190.cpp
        leetCode/archive/_C191.cpp
        leetCode/archive/_C198.cpp
        leetCode/archive/_C199.cpp
        leetCode/archive/_C200.cpp
        leetCode/archive/_C201.cpp
        leetCode/archive/_C202.cpp
        leetCode/archive/_C203.cpp
        leetCode/archive/_C204.cpp
        leetCode/archive/_C205.cpp
        leetCode/archive/_C206.cpp
        leetCode/main.cc
        "PAT/PAT (Basic Level) Practise （中文）/1001.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1002.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1003.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1004.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1005.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1006.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1007.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1008.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1009.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1010.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1011.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1012.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1013.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1014.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1015.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1016.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1017.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1018.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1019.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1020.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1021.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1022.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1023.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1024.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1025.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1026.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1027.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1028.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1029.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1030.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1031.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1032.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1033.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1034.cpp"
        "PAT/PAT (Basic Level) Practise （中文）/1035.cpp"
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0001_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0002_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0003_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0004_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0005_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0006_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0007_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0008_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0009_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0010_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0011_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0012_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0012_mooc_1.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0013_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0014_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0015_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0016_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0017_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0018_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0019_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0020_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0021_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0022_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0023_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0024_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0025_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0026_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0027_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0028_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0029_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0030_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0031_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0032_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0033_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0034_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0035_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0036_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0037_mooc.cpp
        PAT/中国大学MOOC-翁恺-C语言程序设计习题集/d0038_mooc.cpp
        "PAT/中国大学MOOC-陈越、何钦铭-数据结构2015春习题集/00-自测1. 打印沙漏(20).cpp"
        "PAT/中国大学MOOC-陈越、何钦铭-数据结构2015春习题集/00-自测2. 素数对猜想 (20).cpp"
        "PAT/中国大学MOOC-陈越、何钦铭-数据结构2015春习题集/00-自测3. 数组元素循环右移问题 (20).cpp"
        "PAT/中国大学MOOC-陈越、何钦铭-数据结构2015春习题集/00-自测4. Have Fun with Numbers (20).cpp"
        "PAT/中国大学MOOC-陈越、何钦铭-数据结构2015春习题集/00-自测5. Shuffling Machine (20).cpp"
        PAT/中国大学MOOC-陈越、何钦铭-数据结构基础习题集/d0001_mooc_xitiji.cpp
        PAT/中国大学MOOC-陈越、何钦铭-数据结构基础习题集/d0002_mooc.cpp
        PAT/中国大学MOOC-陈越、何钦铭-数据结构基础习题集/d0003_mooc.cpp
        PAT/中国大学MOOC-陈越、何钦铭-数据结构基础习题集/d0004_mooc.cpp
        PAT/中国大学MOOC-陈越、何钦铭-数据结构基础习题集/d0005_mooc.cpp
        九度OJ/archive/_C1005_1.c
        九度OJ/archive/_C1005_2.cc
        九度OJ/archive/_C1006_1.c
        九度OJ/archive/_C1007_1.c
        九度OJ/archive/_C1008_1.cc
        九度OJ/archive/_C1009_1.cc
        九度OJ/archive/_C1010_1.cc
        九度OJ/archive/_C1011_1.cc
        九度OJ/archive/_C1012_1.cc
        九度OJ/archive/_C1013_1.cc
        九度OJ/archive/_C1014_1.cc
        九度OJ/archive/_C1015_1.cc
        九度OJ/archive/_C1016_1.cc
        九度OJ/archive/_C1017_1.cc
        九度OJ/archive/_C1018_1.cc
        九度OJ/archive/_C1019_1.cc
        九度OJ/archive/_C1020_1.cc
        九度OJ/archive/_C1021_1.cc
        九度OJ/archive/_C1022_1.cc
        九度OJ/archive/_C1023_1.cc
        九度OJ/archive/_C1024_1.cc
        九度OJ/archive/_C1025_1.cc
        九度OJ/archive/_C1026_1.cc
        九度OJ/archive/_C1027_1.cc
        九度OJ/archive/_C1028_1.cc
        九度OJ/archive/_C1029_1.cc
        九度OJ/archive/_C1030_1.cc
        九度OJ/archive/_C1031_1.cc
        九度OJ/archive/_C1032_1.cc
        九度OJ/archive/_C1033_1.cc
        九度OJ/archive/_C1034_1.cc
        九度OJ/archive/_C1035_1.cc
        九度OJ/archive/_C1036_1.cc
        九度OJ/archive/_C1037_1.cc
        九度OJ/archive/_C1038_1.cc
        九度OJ/archive/_C1039_1.cc
        九度OJ/archive/_C1040_1.cc
        九度OJ/archive/_C1041_1.cc
        九度OJ/archive/_C1042_1.cc
        九度OJ/archive/_C1043_1.cc
        九度OJ/archive/_C1044_1.cc
        九度OJ/archive/_C1051_1.c
        九度OJ/archive/_C1052_1.c
        九度OJ/archive/_C1053_1.c
        九度OJ/archive/_C1054_1.c
        九度OJ/archive/_C1055_1.c
        九度OJ/archive/_C1056_1.c
        九度OJ/archive/_C1057_1.c
        九度OJ/archive/_C1057_2.cc
        九度OJ/archive/_C1058_1.c
        九度OJ/archive/_C1059_1.c
        九度OJ/archive/_C1060_1.c
        九度OJ/archive/_C1060_2.cc
        九度OJ/archive/_C1061_1.c
        九度OJ/archive/_C1061_2.cc
        九度OJ/archive/_C1062_1.c
        九度OJ/archive/_C1062_2.cc
        九度OJ/archive/_C1063_1.c
        九度OJ/archive/_C1064_1.c
        九度OJ/archive/_C1065_1.c
        九度OJ/archive/_C1066_1.c
        九度OJ/archive/_C1067_1.c
        九度OJ/archive/_C1068_1.c
        九度OJ/archive/_C1069_1.c
        九度OJ/archive/_C1070_1.c
        九度OJ/archive/_C1072_1.c
        九度OJ/archive/_C1073_1.c
        九度OJ/archive/_C1074_1.c
        九度OJ/archive/_C1075_1.c
        九度OJ/archive/_C1076_1.c
        九度OJ/archive/_C1077_1.c
        九度OJ/archive/_C1078_1.c
        九度OJ/archive/_C1079_1.c
        九度OJ/archive/_C1080_1.c
        九度OJ/archive/_C1081_1.c
        九度OJ/archive/_C1082_1.c
        九度OJ/archive/_C1083_1.c
        九度OJ/archive/_C1084_1.c
        九度OJ/archive/_C1085_1.c
        九度OJ/archive/_C1086_1.c
        九度OJ/archive/_C1087_1.cc
        九度OJ/archive/_C1088_1.cc
        九度OJ/archive/_C1090_1.cc
        九度OJ/archive/_C1091_1.cc
        九度OJ/archive/_C1092_1.cc
        九度OJ/archive/_C1093_1.cc
        九度OJ/archive/_C1094_1.cc
        九度OJ/archive/_C1095_1.cc
        九度OJ/archive/_C1096_1.cc
        九度OJ/archive/_C1097_1.cc
        九度OJ/archive/_C1098_1.cc
        九度OJ/archive/_C1099_1.cc
        九度OJ/archive/_C1100_1.cc
        九度OJ/archive/_C1101_1.cc
        九度OJ/archive/_C1102_1.cc
        九度OJ/archive/_C1103_1.cc
        九度OJ/archive/_C1104_1.cc
        九度OJ/archive/_C1105_1.c
        九度OJ/archive/_C1106_1.c
        九度OJ/archive/_C1107_1.c
        九度OJ/archive/_C1108_1.c
        九度OJ/archive/_C1109_1.c
        九度OJ/archive/_C1110_1.cc
        九度OJ/archive/_C1111_1.cc
        九度OJ/archive/_C1112_1.cc
        九度OJ/archive/_C1113_1.cc
        九度OJ/archive/_C1114_1.cc
        九度OJ/archive/_C1115_1.cc
        九度OJ/archive/_C1116_1.cc
        九度OJ/archive/_C1117_1.cc
        九度OJ/archive/_C1118_1.cc
        九度OJ/archive/_C1119_1.cc
        九度OJ/archive/_C1120_1.cc
        九度OJ/archive/_C1121_1.cc
        九度OJ/archive/_C1122_1.cc
        九度OJ/archive/_C1123_1.cc
        九度OJ/archive/_C1124_1.cc
        九度OJ/archive/_C1125_1.cc
        九度OJ/archive/_C1126_1.cc
        九度OJ/archive/_C1127_1.cc
        九度OJ/archive/_C1128_1.cc
        九度OJ/archive/_C1129_1.cc
        九度OJ/archive/_C1130_1.cc
        九度OJ/archive/_C1131_1.cc
        九度OJ/archive/_C1132_1.cc
        九度OJ/archive/_C1133_1.cc
        九度OJ/archive/_C1134_1.cc
        九度OJ/archive/_C1135_1.cc
        九度OJ/archive/_C1136_1.cc
        九度OJ/archive/_C1137_1.cc
        九度OJ/archive/_C1138_1.cc
        九度OJ/archive/_C1139_1.cc
        九度OJ/archive/_C1140_1.cc
        九度OJ/archive/_C1141_1.cc
        九度OJ/archive/_C1142_1.cc
        九度OJ/archive/_C1143_1.cc
        九度OJ/archive/_C1144_1.cc
        九度OJ/archive/_C1145_1.cc
        九度OJ/archive/_C1146_1.cc
        九度OJ/archive/_C1147_1.cc
        九度OJ/archive/_C1148_1.cc
        九度OJ/archive/_C1149_1.cc
        九度OJ/archive/_C1150_1.cc
        九度OJ/archive/_C1151_1.cc
        九度OJ/archive/_C1152_1.cc
        九度OJ/archive/_C1153_1.cc
        九度OJ/archive/_C1154_1.cc
        九度OJ/archive/_C1155_1.cc
        九度OJ/archive/_C1156_1.cc
        九度OJ/archive/_C1158_1.cc
        九度OJ/archive/_C1159_1.cc
        九度OJ/archive/_C1163_1.c
        九度OJ/archive/_C1164_1.c
        九度OJ/archive/_C1165_1.c
        九度OJ/archive/_C1166_1.c
        九度OJ/archive/_C1167_1.c
        九度OJ/archive/_C1168_1.c
        九度OJ/archive/_C1177_1.c
        九度OJ/archive/_C1178_1.c
        九度OJ/archive/_C1182_1.c
        九度OJ/archive/_C1183_1.c
        九度OJ/archive/_C1184_1.c
        九度OJ/archive/_C1185_1.c
        九度OJ/archive/_C1186_1.c
        九度OJ/archive/_C1187_1.c
        九度OJ/archive/_C1188_1.c
        九度OJ/archive/_C1189_1.c
        九度OJ/archive/_C1190_1.c
        九度OJ/archive/_C1191_1.c
        九度OJ/archive/_C1192_1.c
        九度OJ/archive/_C1193_1.c
        九度OJ/archive/_C1194_1.c
        九度OJ/archive/_C1195_1.c
        九度OJ/archive/_C1196_1.c
        九度OJ/archive/_C1197_1.c
        九度OJ/archive/_C1198_1.c
        九度OJ/archive/_C1199_1.c
        九度OJ/archive/_C1200_1.c
        九度OJ/archive/_C1201.c
        九度OJ/archive/_C1202_1.c
        九度OJ/archive/_C1203_1.c
        九度OJ/archive/_C1204_1.c
        九度OJ/archive/_C1205_1.c
        九度OJ/archive/_C1206_1.c
        九度OJ/archive/_C1207_1.cc
        九度OJ/archive/_C1208_1.cc
        九度OJ/archive/_C1366_1.cc
        九度OJ/archive/_C1367_1.cc
        九度OJ/archive/_C1368_1.cc
        九度OJ/archive/_C1384_1.cc
        九度OJ/archive/_C1385_1.cc
        九度OJ/archive/_C1386_1.cc
        九度OJ/archive/_C1387_1.cc
        九度OJ/archive/_C1388_1.cc
        九度OJ/archive/_C1389_1.cc
        九度OJ/archive/_C1390_1.cc
        九度OJ/archive/_C1391_1.cc
        九度OJ/archive/_C1466_1.c
        九度OJ/archive/_C1467_1.c
        九度OJ/archive/_C1470_1.c
        九度OJ/archive/_C1471_1.c
        九度OJ/archive/_C1472_1.c
        九度OJ/archive/_C1473_1.c
        九度OJ/archive/_C1474_1.c
        九度OJ/archive/_C1475_1.c
        九度OJ/archive/_C1476_1.c
        九度OJ/archive/_C1477_1.c
        九度OJ/archive/_C1478_1.c
        九度OJ/archive/_C1488_1.c
        九度OJ/archive/_C1489_1.c
        九度OJ/archive/_C1490.c
        九度OJ/archive/_C1510_1.cc
        九度OJ/archive/_C1511_1.cc
        九度OJ/archive/_C1512_1.cc
        九度OJ/archive/_C1513_1.cc
        九度OJ/archive/_C1514_1.cc
        九度OJ/archive/_C1515_1.cc
        九度OJ/archive/_C1516_1.cc
        九度OJ/archive/_C1517_1.cc
        九度OJ/archive/_C1518_1.cc
        九度OJ/archive/_C1519_1.cc
        九度OJ/archive/_C1520_1.cc
        九度OJ/archive/_C1521_1.cc
        九度OJ/archive/_C1522_1.cc
        九度OJ/archive/_C1523_1.cc
        九度OJ/archive/_华科2013_1.c
        九度OJ/archive/_华科2013_2.c
        九度OJ/archive/_华科2013_3.c
        九度OJ/archive/_华科2014_1.c
        九度OJ/archive/_华科2014_2.c
        九度OJ/archive/_华科2014_3.c
        华为OJ/archive/_判断两个IP是否属于同一子网.cc
        华为OJ/archive/_合唱队.cc
        华为OJ/archive/_名字的漂亮度.cc
        华为OJ/archive/_图片整理.c
        华为OJ/archive/_字符串加密.cc
        华为OJ/archive/_字符串加解密.cc
        华为OJ/archive/_字符串最后一个单词的长度.cc
        华为OJ/archive/_学英语.cc
        华为OJ/archive/_称砝码.cc
        华为OJ/archive/_蛇形矩阵.cc
        华为OJ/archive/_输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数.cc
        华为OJ/archive/_闯关_表示数字.cc
        华为OJ/archive/_（练习用）挑7.cc
        华为OJ/future_net/lib_io.h
        华为OJ/future_net/lib_record.h
        华为OJ/future_net/lib_time.h
        华为OJ/future_net/main.cpp
        华为OJ/future_net/route.cpp
        华为OJ/future_net/route.h
        牛客网笔试/archive/_2016网易研发工程师——小易的升级之路.cc
        牛客网笔试/archive/_2016网易研发工程师——扫描透镜.cc
        牛客网笔试/archive/_2016网易研发工程师——炮台攻击.cc
        牛客网笔试/archive/_[Offer收割]编程练习赛2_买零食.cc
        牛客网笔试/archive/_[Offer收割]编程练习赛2_清理海报.cc
        牛客网笔试/archive/_华为2016校园招聘——最高分多少.cc
        牛客网笔试/archive/_华为2016校园招聘——简单错误记录.cc
        牛客网笔试/archive/_华为研发工程师——明明的随机数.cc
        牛客网笔试/archive/_华为研发工程师——汽水瓶.cc
        牛客网笔试/archive/_华为研发工程师——进制转换.cc
        牛客网笔试/archive/_蘑菇街2016研发工程师_回文串.cc
        牛客网笔试/archive/_蘑菇街2016研发工程师_投篮游戏.cc
        牛客网笔试/archive/_蘑菇街2016研发工程师_搬圆桌.cc
        牛客网笔试/archive/_蘑菇街2016研发工程师_最大间隔.cc
        牛客网笔试/archive/_蘑菇街2016研发工程师_聊天.cc)
