; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.timeval = type { i64, i64 }

@a1 = global i32 1
@a2 = global i32 2
@a3 = global i32 3
@a4 = global i32 4
@a5 = global i32 5
@a6 = global i32 6
@a7 = global i32 7
@a8 = global i32 8
@a9 = global i32 9
@a10 = global i32 10
@a11 = global i32 11
@a12 = global i32 12
@a13 = global i32 13
@a14 = global i32 14
@a15 = global i32 15
@a16 = global i32 16
@a17 = global i32 1
@a18 = global i32 2
@a19 = global i32 3
@a20 = global i32 4
@a21 = global i32 5
@a22 = global i32 6
@a23 = global i32 7
@a24 = global i32 8
@a25 = global i32 9
@a26 = global i32 10
@a27 = global i32 11
@a28 = global i32 12
@a29 = global i32 13
@a30 = global i32 14
@a31 = global i32 15
@a32 = global i32 16
@llvm.global_ctors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @before_main, ptr null }]
@llvm.global_dtors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @after_main, ptr null }]
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%d:\00", align 1
@.str.3 = private unnamed_addr constant [4 x i8] c" %d\00", align 1
@.str.4 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@_sysy_us = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_s = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_m = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_h = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_idx = dso_local global i32 0, align 4
@stderr = external global ptr, align 8
@.str.5 = private unnamed_addr constant [35 x i8] c"Timer@%04d-%04d: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_l1 = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_l2 = dso_local global [1024 x i32] zeroinitializer, align 16
@.str.6 = private unnamed_addr constant [25 x i8] c"TOTAL: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_start = dso_local global %struct.timeval zeroinitializer, align 8
@_sysy_end = dso_local global %struct.timeval zeroinitializer, align 8

define i32 @func(i32 %r100, i32 %r102) {
bb1:
  %r572 = add i32 0, 0
  %r573 = add i32 %r100, 0
  %r574 = add i32 0, 0
  %r575 = add i32 %r102, 0
  %r576 = add i32 0, 0
  %r577 = add i32 %r573, %r575
  %r578 = add i32 %r577, 0
  %r579 = add i32 0, 0
  %r580 = add i32 0, 0
  %r581 = add i32 0, 0
  %r582 = add i32 0, 0
  %r583 = add i32 0, 0
  %r584 = add i32 0, 0
  %r585 = add i32 0, 0
  %r586 = add i32 0, 0
  %r587 = add i32 0, 0
  %r588 = add i32 0, 0
  %r589 = add i32 0, 0
  %r590 = add i32 0, 0
  %r591 = add i32 0, 0
  %r592 = add i32 0, 0
  %r593 = add i32 0, 0
  %r594 = add i32 0, 0
  %r595 = add i32 0, 0
  %r596 = add i32 0, 0
  %r597 = add i32 0, 0
  %r598 = add i32 0, 0
  %r599 = add i32 0, 0
  %r600 = add i32 0, 0
  %r601 = add i32 0, 0
  %r602 = add i32 0, 0
  %r603 = add i32 0, 0
  %r604 = add i32 0, 0
  %r605 = add i32 0, 0
  %r606 = add i32 0, 0
  %r607 = add i32 0, 0
  %r608 = add i32 0, 0
  %r609 = add i32 0, 0
  %r610 = add i32 0, 0
  %r611 = add i32 0, 0
  %r612 = add i32 0, 0
  %r613 = add i32 0, 0
  %r614 = add i32 0, 0
  %r615 = call i32 @getint()
  %r616 = add i32 %r615, 0
  %r617 = call i32 @getint()
  %r618 = add i32 %r617, 0
  %r619 = call i32 @getint()
  %r620 = add i32 %r619, 0
  %r621 = call i32 @getint()
  %r622 = add i32 %r621, 0
  %r623 = add i32 1, %r616
  %r624 = load i32, ptr @a1, align 4
  %r625 = add i32 %r623, %r624
  %r626 = add i32 %r625, 0
  %r627 = add i32 2, %r618
  %r628 = load i32, ptr @a2, align 4
  %r629 = add i32 %r627, %r628
  %r630 = add i32 %r629, 0
  %r631 = add i32 3, %r620
  %r632 = load i32, ptr @a3, align 4
  %r633 = add i32 %r631, %r632
  %r634 = add i32 %r633, 0
  %r635 = add i32 4, %r622
  %r636 = load i32, ptr @a4, align 4
  %r637 = add i32 %r635, %r636
  %r638 = add i32 %r637, 0
  %r639 = add i32 1, %r626
  %r640 = load i32, ptr @a5, align 4
  %r641 = add i32 %r639, %r640
  %r642 = add i32 %r641, 0
  %r643 = add i32 2, %r630
  %r644 = load i32, ptr @a6, align 4
  %r645 = add i32 %r643, %r644
  %r646 = add i32 %r645, 0
  %r647 = add i32 3, %r634
  %r648 = load i32, ptr @a7, align 4
  %r649 = add i32 %r647, %r648
  %r650 = add i32 %r649, 0
  %r651 = add i32 4, %r638
  %r652 = load i32, ptr @a8, align 4
  %r653 = add i32 %r651, %r652
  %r654 = add i32 %r653, 0
  %r655 = add i32 1, %r642
  %r656 = load i32, ptr @a9, align 4
  %r657 = add i32 %r655, %r656
  %r658 = add i32 %r657, 0
  %r659 = add i32 2, %r646
  %r660 = load i32, ptr @a10, align 4
  %r661 = add i32 %r659, %r660
  %r662 = add i32 %r661, 0
  %r663 = add i32 3, %r650
  %r664 = load i32, ptr @a11, align 4
  %r665 = add i32 %r663, %r664
  %r666 = add i32 %r665, 0
  %r667 = add i32 4, %r654
  %r668 = load i32, ptr @a12, align 4
  %r669 = add i32 %r667, %r668
  %r670 = add i32 %r669, 0
  %r671 = add i32 1, %r658
  %r672 = load i32, ptr @a13, align 4
  %r673 = add i32 %r671, %r672
  %r674 = add i32 %r673, 0
  %r675 = add i32 2, %r662
  %r676 = load i32, ptr @a14, align 4
  %r677 = add i32 %r675, %r676
  %r678 = add i32 %r677, 0
  %r679 = add i32 3, %r666
  %r680 = load i32, ptr @a15, align 4
  %r681 = add i32 %r679, %r680
  %r682 = add i32 %r681, 0
  %r683 = add i32 4, %r670
  %r684 = load i32, ptr @a16, align 4
  %r685 = add i32 %r683, %r684
  %r686 = add i32 %r685, 0
  %r687 = add i32 1, %r674
  %r688 = load i32, ptr @a17, align 4
  %r689 = add i32 %r687, %r688
  %r690 = add i32 %r689, 0
  %r691 = add i32 2, %r678
  %r692 = load i32, ptr @a18, align 4
  %r693 = add i32 %r691, %r692
  %r694 = add i32 %r693, 0
  %r695 = add i32 3, %r682
  %r696 = load i32, ptr @a19, align 4
  %r697 = add i32 %r695, %r696
  %r698 = add i32 %r697, 0
  %r699 = add i32 4, %r686
  %r700 = load i32, ptr @a20, align 4
  %r701 = add i32 %r699, %r700
  %r702 = add i32 %r701, 0
  %r703 = add i32 1, %r690
  %r704 = load i32, ptr @a21, align 4
  %r705 = add i32 %r703, %r704
  %r706 = add i32 %r705, 0
  %r707 = add i32 2, %r694
  %r708 = load i32, ptr @a22, align 4
  %r709 = add i32 %r707, %r708
  %r710 = add i32 %r709, 0
  %r711 = add i32 3, %r698
  %r712 = load i32, ptr @a23, align 4
  %r713 = add i32 %r711, %r712
  %r714 = add i32 %r713, 0
  %r715 = add i32 4, %r702
  %r716 = load i32, ptr @a24, align 4
  %r717 = add i32 %r715, %r716
  %r718 = add i32 %r717, 0
  %r719 = add i32 1, %r706
  %r720 = load i32, ptr @a25, align 4
  %r721 = add i32 %r719, %r720
  %r722 = add i32 %r721, 0
  %r723 = add i32 2, %r710
  %r724 = load i32, ptr @a26, align 4
  %r725 = add i32 %r723, %r724
  %r726 = add i32 %r725, 0
  %r727 = add i32 3, %r714
  %r728 = load i32, ptr @a27, align 4
  %r729 = add i32 %r727, %r728
  %r730 = add i32 %r729, 0
  %r731 = add i32 4, %r718
  %r732 = load i32, ptr @a28, align 4
  %r733 = add i32 %r731, %r732
  %r734 = add i32 %r733, 0
  %r735 = add i32 1, %r722
  %r736 = load i32, ptr @a29, align 4
  %r737 = add i32 %r735, %r736
  %r738 = add i32 %r737, 0
  %r739 = add i32 2, %r726
  %r740 = load i32, ptr @a30, align 4
  %r741 = add i32 %r739, %r740
  %r742 = add i32 %r741, 0
  %r743 = add i32 3, %r730
  %r744 = load i32, ptr @a31, align 4
  %r745 = add i32 %r743, %r744
  %r746 = add i32 %r745, 0
  %r747 = add i32 4, %r734
  %r748 = load i32, ptr @a32, align 4
  %r749 = add i32 %r747, %r748
  %r750 = add i32 %r749, 0
  %r751 = sub i32 %r573, %r575
  %r752 = add i32 %r751, 10
  %r753 = add i32 %r752, 0
  %r754 = add i32 1, %r722
  %r755 = load i32, ptr @a29, align 4
  %r756 = add i32 %r754, %r755
  %r757 = add i32 %r756, 0
  %r758 = add i32 2, %r726
  %r759 = load i32, ptr @a30, align 4
  %r760 = add i32 %r758, %r759
  %r761 = add i32 %r760, 0
  %r762 = add i32 3, %r730
  %r763 = load i32, ptr @a31, align 4
  %r764 = add i32 %r762, %r763
  %r765 = add i32 %r764, 0
  %r766 = add i32 4, %r734
  %r767 = load i32, ptr @a32, align 4
  %r768 = add i32 %r766, %r767
  %r769 = add i32 %r768, 0
  %r770 = add i32 1, %r706
  %r771 = load i32, ptr @a25, align 4
  %r772 = add i32 %r770, %r771
  %r773 = add i32 %r772, 0
  %r774 = add i32 2, %r710
  %r775 = load i32, ptr @a26, align 4
  %r776 = add i32 %r774, %r775
  %r777 = add i32 %r776, 0
  %r778 = add i32 3, %r714
  %r779 = load i32, ptr @a27, align 4
  %r780 = add i32 %r778, %r779
  %r781 = add i32 %r780, 0
  %r782 = add i32 4, %r718
  %r783 = load i32, ptr @a28, align 4
  %r784 = add i32 %r782, %r783
  %r785 = add i32 %r784, 0
  %r786 = add i32 1, %r690
  %r787 = load i32, ptr @a21, align 4
  %r788 = add i32 %r786, %r787
  %r789 = add i32 %r788, 0
  %r790 = add i32 2, %r694
  %r791 = load i32, ptr @a22, align 4
  %r792 = add i32 %r790, %r791
  %r793 = add i32 %r792, 0
  %r794 = add i32 3, %r698
  %r795 = load i32, ptr @a23, align 4
  %r796 = add i32 %r794, %r795
  %r797 = add i32 %r796, 0
  %r798 = add i32 4, %r702
  %r799 = load i32, ptr @a24, align 4
  %r800 = add i32 %r798, %r799
  %r801 = add i32 %r800, 0
  %r802 = add i32 1, %r674
  %r803 = load i32, ptr @a17, align 4
  %r804 = add i32 %r802, %r803
  %r805 = add i32 %r804, 0
  %r806 = add i32 2, %r678
  %r807 = load i32, ptr @a18, align 4
  %r808 = add i32 %r806, %r807
  %r809 = add i32 %r808, 0
  %r810 = add i32 3, %r682
  %r811 = load i32, ptr @a19, align 4
  %r812 = add i32 %r810, %r811
  %r813 = add i32 %r812, 0
  %r814 = add i32 4, %r686
  %r815 = load i32, ptr @a20, align 4
  %r816 = add i32 %r814, %r815
  %r817 = add i32 %r816, 0
  %r818 = add i32 1, %r658
  %r819 = load i32, ptr @a13, align 4
  %r820 = add i32 %r818, %r819
  %r821 = add i32 %r820, 0
  %r822 = add i32 2, %r662
  %r823 = load i32, ptr @a14, align 4
  %r824 = add i32 %r822, %r823
  %r825 = add i32 %r824, 0
  %r826 = add i32 3, %r666
  %r827 = load i32, ptr @a15, align 4
  %r828 = add i32 %r826, %r827
  %r829 = add i32 %r828, 0
  %r830 = add i32 4, %r670
  %r831 = load i32, ptr @a16, align 4
  %r832 = add i32 %r830, %r831
  %r833 = add i32 %r832, 0
  %r834 = add i32 1, %r642
  %r835 = load i32, ptr @a9, align 4
  %r836 = add i32 %r834, %r835
  %r837 = add i32 %r836, 0
  %r838 = add i32 2, %r646
  %r839 = load i32, ptr @a10, align 4
  %r840 = add i32 %r838, %r839
  %r841 = add i32 %r840, 0
  %r842 = add i32 3, %r650
  %r843 = load i32, ptr @a11, align 4
  %r844 = add i32 %r842, %r843
  %r845 = add i32 %r844, 0
  %r846 = add i32 4, %r654
  %r847 = load i32, ptr @a12, align 4
  %r848 = add i32 %r846, %r847
  %r849 = add i32 %r848, 0
  %r850 = add i32 1, %r626
  %r851 = load i32, ptr @a5, align 4
  %r852 = add i32 %r850, %r851
  %r853 = add i32 %r852, 0
  %r854 = add i32 2, %r630
  %r855 = load i32, ptr @a6, align 4
  %r856 = add i32 %r854, %r855
  %r857 = add i32 %r856, 0
  %r858 = add i32 3, %r634
  %r859 = load i32, ptr @a7, align 4
  %r860 = add i32 %r858, %r859
  %r861 = add i32 %r860, 0
  %r862 = add i32 4, %r638
  %r863 = load i32, ptr @a8, align 4
  %r864 = add i32 %r862, %r863
  %r865 = add i32 %r864, 0
  %r866 = add i32 1, %r616
  %r867 = load i32, ptr @a1, align 4
  %r868 = add i32 %r866, %r867
  %r869 = add i32 %r868, 0
  %r870 = add i32 2, %r618
  %r871 = load i32, ptr @a2, align 4
  %r872 = add i32 %r870, %r871
  %r873 = add i32 %r872, 0
  %r874 = add i32 3, %r620
  %r875 = load i32, ptr @a3, align 4
  %r876 = add i32 %r874, %r875
  %r877 = add i32 %r876, 0
  %r878 = add i32 4, %r622
  %r879 = load i32, ptr @a4, align 4
  %r880 = add i32 %r878, %r879
  %r881 = add i32 %r880, 0
  %r882 = add i32 1, %r616
  %r883 = load i32, ptr @a1, align 4
  %r884 = add i32 %r882, %r883
  %r885 = add i32 %r884, 0
  %r886 = add i32 2, %r618
  %r887 = load i32, ptr @a2, align 4
  %r888 = add i32 %r886, %r887
  %r889 = add i32 %r888, 0
  %r890 = add i32 3, %r620
  %r891 = load i32, ptr @a3, align 4
  %r892 = add i32 %r890, %r891
  %r893 = add i32 %r892, 0
  %r894 = add i32 4, %r622
  %r895 = load i32, ptr @a4, align 4
  %r896 = add i32 %r894, %r895
  %r897 = add i32 %r896, 0
  %r898 = add i32 %r753, %r616
  %r899 = add i32 %r898, %r618
  %r900 = add i32 %r899, %r620
  %r901 = add i32 %r900, %r622
  %r902 = sub i32 %r901, %r885
  %r903 = sub i32 %r902, %r889
  %r904 = sub i32 %r903, %r893
  %r905 = sub i32 %r904, %r897
  %r906 = add i32 %r905, %r853
  %r907 = add i32 %r906, %r857
  %r908 = add i32 %r907, %r861
  %r909 = add i32 %r908, %r865
  %r910 = sub i32 %r909, %r837
  %r911 = sub i32 %r910, %r841
  %r912 = sub i32 %r911, %r845
  %r913 = sub i32 %r912, %r849
  %r914 = add i32 %r913, %r821
  %r915 = add i32 %r914, %r825
  %r916 = add i32 %r915, %r829
  %r917 = add i32 %r916, %r833
  %r918 = sub i32 %r917, %r805
  %r919 = sub i32 %r918, %r809
  %r920 = sub i32 %r919, %r813
  %r921 = sub i32 %r920, %r817
  %r922 = add i32 %r921, %r789
  %r923 = add i32 %r922, %r793
  %r924 = add i32 %r923, %r797
  %r925 = add i32 %r924, %r801
  %r926 = sub i32 %r925, %r773
  %r927 = sub i32 %r926, %r777
  %r928 = sub i32 %r927, %r781
  %r929 = sub i32 %r928, %r785
  %r930 = add i32 %r929, %r757
  %r931 = add i32 %r930, %r761
  %r932 = add i32 %r931, %r765
  %r933 = add i32 %r932, %r769
  %r934 = load i32, ptr @a1, align 4
  %r935 = add i32 %r933, %r934
  %r936 = load i32, ptr @a2, align 4
  %r937 = sub i32 %r935, %r936
  %r938 = load i32, ptr @a3, align 4
  %r939 = add i32 %r937, %r938
  %r940 = load i32, ptr @a4, align 4
  %r941 = sub i32 %r939, %r940
  %r942 = load i32, ptr @a5, align 4
  %r943 = add i32 %r941, %r942
  %r944 = load i32, ptr @a6, align 4
  %r945 = sub i32 %r943, %r944
  %r946 = load i32, ptr @a7, align 4
  %r947 = add i32 %r945, %r946
  %r948 = load i32, ptr @a8, align 4
  %r949 = sub i32 %r947, %r948
  %r950 = load i32, ptr @a9, align 4
  %r951 = add i32 %r949, %r950
  %r952 = load i32, ptr @a10, align 4
  %r953 = sub i32 %r951, %r952
  %r954 = load i32, ptr @a11, align 4
  %r955 = add i32 %r953, %r954
  %r956 = load i32, ptr @a12, align 4
  %r957 = sub i32 %r955, %r956
  %r958 = load i32, ptr @a13, align 4
  %r959 = add i32 %r957, %r958
  %r960 = load i32, ptr @a14, align 4
  %r961 = sub i32 %r959, %r960
  %r962 = load i32, ptr @a15, align 4
  %r963 = add i32 %r961, %r962
  %r964 = load i32, ptr @a16, align 4
  %r965 = sub i32 %r963, %r964
  %r966 = load i32, ptr @a17, align 4
  %r967 = add i32 %r965, %r966
  %r968 = load i32, ptr @a18, align 4
  %r969 = sub i32 %r967, %r968
  %r970 = load i32, ptr @a19, align 4
  %r971 = add i32 %r969, %r970
  %r972 = load i32, ptr @a20, align 4
  %r973 = sub i32 %r971, %r972
  %r974 = load i32, ptr @a21, align 4
  %r975 = add i32 %r973, %r974
  %r976 = load i32, ptr @a22, align 4
  %r977 = sub i32 %r975, %r976
  %r978 = load i32, ptr @a23, align 4
  %r979 = add i32 %r977, %r978
  %r980 = load i32, ptr @a24, align 4
  %r981 = sub i32 %r979, %r980
  %r982 = load i32, ptr @a25, align 4
  %r983 = add i32 %r981, %r982
  %r984 = load i32, ptr @a26, align 4
  %r985 = sub i32 %r983, %r984
  %r986 = load i32, ptr @a27, align 4
  %r987 = add i32 %r985, %r986
  %r988 = load i32, ptr @a28, align 4
  %r989 = sub i32 %r987, %r988
  %r990 = load i32, ptr @a29, align 4
  %r991 = add i32 %r989, %r990
  %r992 = load i32, ptr @a30, align 4
  %r993 = sub i32 %r991, %r992
  %r994 = load i32, ptr @a31, align 4
  %r995 = add i32 %r993, %r994
  %r996 = load i32, ptr @a32, align 4
  %r997 = sub i32 %r995, %r996
  ret i32 %r997
}

define i32 @main() {
bb2:
  call void @_sysy_starttime(i32 87)
  %r998 = add i32 0, 0
  %r999 = add i32 0, 0
  %r1000 = call i32 @getint()
  %r1001 = add i32 %r1000, 0
  %r1002 = mul i32 2, 9
  %r1003 = add i32 %r1001, %r1002
  %r1004 = add i32 %r1003, 0
  %r1005 = call i32 @func(i32 %r1001, i32 %r1004)
  %r1006 = add i32 %r1005, 0
  call void @putint(i32 %r1006)
  call void @_sysy_stoptime(i32 93)
  ret i32 %r1006
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @before_main() #0 {
  %1 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  br label %2

2:                                                ; preds = %18, %0
  %3 = load i32, ptr %1, align 4
  %4 = icmp slt i32 %3, 1024
  br i1 %4, label %5, label %21

5:                                                ; preds = %2
  %6 = load i32, ptr %1, align 4
  %7 = sext i32 %6 to i64
  %8 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %7
  store i32 0, ptr %8, align 4
  %9 = load i32, ptr %1, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %10
  store i32 0, ptr %11, align 4
  %12 = load i32, ptr %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %13
  store i32 0, ptr %14, align 4
  %15 = load i32, ptr %1, align 4
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %16
  store i32 0, ptr %17, align 4
  br label %18

18:                                               ; preds = %5
  %19 = load i32, ptr %1, align 4
  %20 = add nsw i32 %19, 1
  store i32 %20, ptr %1, align 4
  br label %2, !llvm.loop !6

21:                                               ; preds = %2
  store i32 1, ptr @_sysy_idx, align 4
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @after_main() #0 {
  %1 = alloca i32, align 4
  store i32 1, ptr %1, align 4
  br label %2

2:                                                ; preds = %63, %0
  %3 = load i32, ptr %1, align 4
  %4 = load i32, ptr @_sysy_idx, align 4
  %5 = icmp slt i32 %3, %4
  br i1 %5, label %6, label %66

6:                                                ; preds = %2
  %7 = load ptr, ptr @stderr, align 8
  %8 = load i32, ptr %1, align 4
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds [1024 x i32], ptr @_sysy_l1, i64 0, i64 %9
  %11 = load i32, ptr %10, align 4
  %12 = load i32, ptr %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], ptr @_sysy_l2, i64 0, i64 %13
  %15 = load i32, ptr %14, align 4
  %16 = load i32, ptr %1, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %17
  %19 = load i32, ptr %18, align 4
  %20 = load i32, ptr %1, align 4
  %21 = sext i32 %20 to i64
  %22 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %21
  %23 = load i32, ptr %22, align 4
  %24 = load i32, ptr %1, align 4
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %25
  %27 = load i32, ptr %26, align 4
  %28 = load i32, ptr %1, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %29
  %31 = load i32, ptr %30, align 4
  %32 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %7, ptr noundef @.str.5, i32 noundef %11, i32 noundef %15, i32 noundef %19, i32 noundef %23, i32 noundef %27, i32 noundef %31)
  %33 = load i32, ptr %1, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %34
  %36 = load i32, ptr %35, align 4
  %37 = load i32, ptr @_sysy_us, align 16
  %38 = add nsw i32 %37, %36
  store i32 %38, ptr @_sysy_us, align 16
  %39 = load i32, ptr %1, align 4
  %40 = sext i32 %39 to i64
  %41 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %40
  %42 = load i32, ptr %41, align 4
  %43 = load i32, ptr @_sysy_s, align 16
  %44 = add nsw i32 %43, %42
  store i32 %44, ptr @_sysy_s, align 16
  %45 = load i32, ptr @_sysy_us, align 16
  %46 = srem i32 %45, 1000000
  store i32 %46, ptr @_sysy_us, align 16
  %47 = load i32, ptr %1, align 4
  %48 = sext i32 %47 to i64
  %49 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %48
  %50 = load i32, ptr %49, align 4
  %51 = load i32, ptr @_sysy_m, align 16
  %52 = add nsw i32 %51, %50
  store i32 %52, ptr @_sysy_m, align 16
  %53 = load i32, ptr @_sysy_s, align 16
  %54 = srem i32 %53, 60
  store i32 %54, ptr @_sysy_s, align 16
  %55 = load i32, ptr %1, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %56
  %58 = load i32, ptr %57, align 4
  %59 = load i32, ptr @_sysy_h, align 16
  %60 = add nsw i32 %59, %58
  store i32 %60, ptr @_sysy_h, align 16
  %61 = load i32, ptr @_sysy_m, align 16
  %62 = srem i32 %61, 60
  store i32 %62, ptr @_sysy_m, align 16
  br label %63

63:                                               ; preds = %6
  %64 = load i32, ptr %1, align 4
  %65 = add nsw i32 %64, 1
  store i32 %65, ptr %1, align 4
  br label %2, !llvm.loop !8

66:                                               ; preds = %2
  %67 = load ptr, ptr @stderr, align 8
  %68 = load i32, ptr @_sysy_h, align 16
  %69 = load i32, ptr @_sysy_m, align 16
  %70 = load i32, ptr @_sysy_s, align 16
  %71 = load i32, ptr @_sysy_us, align 16
  %72 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %67, ptr noundef @.str.6, i32 noundef %68, i32 noundef %69, i32 noundef %70, i32 noundef %71)
  ret void
}

declare i32 @fprintf(ptr noundef, ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getint() #0 {
  %1 = alloca i32, align 4
  %2 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str, ptr noundef %1)
  %3 = load i32, ptr %1, align 4
  ret i32 %3
}

declare i32 @__isoc99_scanf(ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getch() #0 {
  %1 = alloca i8, align 1
  %2 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str.1, ptr noundef %1)
  %3 = load i8, ptr %1, align 1
  %4 = sext i8 %3 to i32
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getarray(ptr noundef %0) #0 {
  %2 = alloca ptr, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store ptr %0, ptr %2, align 8
  %5 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str, ptr noundef %3)
  store i32 0, ptr %4, align 4
  br label %6

6:                                                ; preds = %16, %1
  %7 = load i32, ptr %4, align 4
  %8 = load i32, ptr %3, align 4
  %9 = icmp slt i32 %7, %8
  br i1 %9, label %10, label %19

10:                                               ; preds = %6
  %11 = load ptr, ptr %2, align 8
  %12 = load i32, ptr %4, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds i32, ptr %11, i64 %13
  %15 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str, ptr noundef %14)
  br label %16

16:                                               ; preds = %10
  %17 = load i32, ptr %4, align 4
  %18 = add nsw i32 %17, 1
  store i32 %18, ptr %4, align 4
  br label %6, !llvm.loop !9

19:                                               ; preds = %6
  %20 = load i32, ptr %3, align 4
  ret i32 %20
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putint(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %3)
  ret void
}

declare i32 @printf(ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putch(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %3)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putarray(i32 noundef %0, ptr noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store ptr %1, ptr %4, align 8
  %6 = load i32, ptr %3, align 4
  %7 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %6)
  store i32 0, ptr %5, align 4
  br label %8

8:                                                ; preds = %19, %2
  %9 = load i32, ptr %5, align 4
  %10 = load i32, ptr %3, align 4
  %11 = icmp slt i32 %9, %10
  br i1 %11, label %12, label %22

12:                                               ; preds = %8
  %13 = load ptr, ptr %4, align 8
  %14 = load i32, ptr %5, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds i32, ptr %13, i64 %15
  %17 = load i32, ptr %16, align 4
  %18 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %17)
  br label %19

19:                                               ; preds = %12
  %20 = load i32, ptr %5, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, ptr %5, align 4
  br label %8, !llvm.loop !10

22:                                               ; preds = %8
  %23 = call i32 (ptr, ...) @printf(ptr noundef @.str.4)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_sysy_starttime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = load i32, ptr @_sysy_idx, align 4
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds [1024 x i32], ptr @_sysy_l1, i64 0, i64 %5
  store i32 %3, ptr %6, align 4
  %7 = call i32 @gettimeofday(ptr noundef @_sysy_start, ptr noundef null) #3
  ret void
}

; Function Attrs: nounwind
declare i32 @gettimeofday(ptr noundef, ptr noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_sysy_stoptime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = call i32 @gettimeofday(ptr noundef @_sysy_end, ptr noundef null) #3
  %4 = load i32, ptr %2, align 4
  %5 = load i32, ptr @_sysy_idx, align 4
  %6 = sext i32 %5 to i64
  %7 = getelementptr inbounds [1024 x i32], ptr @_sysy_l2, i64 0, i64 %6
  store i32 %4, ptr %7, align 4
  %8 = load i64, ptr @_sysy_end, align 8
  %9 = load i64, ptr @_sysy_start, align 8
  %10 = sub nsw i64 %8, %9
  %11 = mul nsw i64 1000000, %10
  %12 = load i64, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_end, i32 0, i32 1), align 8
  %13 = add nsw i64 %11, %12
  %14 = load i64, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_start, i32 0, i32 1), align 8
  %15 = sub nsw i64 %13, %14
  %16 = load i32, ptr @_sysy_idx, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %17
  %19 = load i32, ptr %18, align 4
  %20 = sext i32 %19 to i64
  %21 = add nsw i64 %20, %15
  %22 = trunc i64 %21 to i32
  store i32 %22, ptr %18, align 4
  %23 = load i32, ptr @_sysy_idx, align 4
  %24 = sext i32 %23 to i64
  %25 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %24
  %26 = load i32, ptr %25, align 4
  %27 = sdiv i32 %26, 1000000
  %28 = load i32, ptr @_sysy_idx, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %29
  %31 = load i32, ptr %30, align 4
  %32 = add nsw i32 %31, %27
  store i32 %32, ptr %30, align 4
  %33 = load i32, ptr @_sysy_idx, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %34
  %36 = load i32, ptr %35, align 4
  %37 = srem i32 %36, 1000000
  store i32 %37, ptr %35, align 4
  %38 = load i32, ptr @_sysy_idx, align 4
  %39 = sext i32 %38 to i64
  %40 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %39
  %41 = load i32, ptr %40, align 4
  %42 = sdiv i32 %41, 60
  %43 = load i32, ptr @_sysy_idx, align 4
  %44 = sext i32 %43 to i64
  %45 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %44
  %46 = load i32, ptr %45, align 4
  %47 = add nsw i32 %46, %42
  store i32 %47, ptr %45, align 4
  %48 = load i32, ptr @_sysy_idx, align 4
  %49 = sext i32 %48 to i64
  %50 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %49
  %51 = load i32, ptr %50, align 4
  %52 = srem i32 %51, 60
  store i32 %52, ptr %50, align 4
  %53 = load i32, ptr @_sysy_idx, align 4
  %54 = sext i32 %53 to i64
  %55 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %54
  %56 = load i32, ptr %55, align 4
  %57 = sdiv i32 %56, 60
  %58 = load i32, ptr @_sysy_idx, align 4
  %59 = sext i32 %58 to i64
  %60 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %59
  %61 = load i32, ptr %60, align 4
  %62 = add nsw i32 %61, %57
  store i32 %62, ptr %60, align 4
  %63 = load i32, ptr @_sysy_idx, align 4
  %64 = sext i32 %63 to i64
  %65 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %64
  %66 = load i32, ptr %65, align 4
  %67 = srem i32 %66, 60
  store i32 %67, ptr %65, align 4
  %68 = load i32, ptr @_sysy_idx, align 4
  %69 = add nsw i32 %68, 1
  store i32 %69, ptr @_sysy_idx, align 4
  ret void
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1, !2, !3, !4, !5}

!0 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 8, !"PIC Level", i32 2}
!3 = !{i32 7, !"PIE Level", i32 2}
!4 = !{i32 7, !"uwtable", i32 1}
!5 = !{i32 7, !"frame-pointer", i32 2}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
!10 = distinct !{!10, !7}
