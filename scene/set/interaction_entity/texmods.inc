;win = w
;camo_win = cw
;camo2_win = c2w
;zem_city_win = zcyw
;zem_camo_win = zcw
;zem_gray_win = zgw
;zem_win = zw
;gray_win = gw
;orange_camo_win = ocw
;orange_win = ow

;desert = d
;camo_desert = cd
;camo2_desert = c2d
;zem_camo_desert = zcd
;zem_desert = zd
;orange_camo_desert = zcd
;orange_desert = od

;forest = f
;camo_forest = cf
;camo2_forest = c2f
;camo3_forest = c3f
;zem_camo_forest = zcf
;orange_camo_forest = ocf

;city = c
;camo_city = cc
;gray_city = gc
;zem_city = zc
;zem_gray_city = zgc
;orange_city = oc

;======== SET ========

(define "tex_rand_1"
	{tex_mod "%name1"}
)
(define "tex_rand_2"
	{if rand 0.5
		{tex_mod "%name1"}
	else
		{tex_mod "%name2"}
	}
)
(define "tex_rand_3"
	{if rand 0.33
		{tex_mod "%name1"}
	else rand 0.5
		{tex_mod "%name2"}
	else
		{tex_mod "%name3"}
	}
)
(define "tex_rand_4"
	{if rand 0.25
		{tex_mod "%name1"}
	else rand 0.33
		{tex_mod "%name2"}
	else rand 0.5
		{tex_mod "%name3"}
	else
		{tex_mod "%name4"}
	}
)
(define "tex_rand_5"
	{if rand 0.2
		{tex_mod "%name1"}
	else rand 0.25
		{tex_mod "%name2"}
	else rand 0.33
		{tex_mod "%name3"}
	else rand 0.5
		{tex_mod "%name4"}
	else
		{tex_mod "%name5"}
	}
)
(define "tex_rand_6"
	{if rand 0.166
		{tex_mod "%name1"}
	else rand 0.2
		{tex_mod "%name2"}
	else rand 0.25
		{tex_mod "%name3"}
	else rand 0.33
		{tex_mod "%name4"}
	else rand 0.5
		{tex_mod "%name5"}
	else
		{tex_mod "%name6"}
	}
)

(define "select_biom"
	{if game_param "biom" "snow"
		("tex_rand_%snum" name1(%snow1) name2(%snow2) name3(%snow3) name4(%snow4) name5(%snow5) name6(%snow6))
	else game_param "biom" "forest"
		("tex_rand_%fnum" name1(%forest1) name2(%forest2) name3(%forest3) name4(%forest4) name5(%forest5) name6(%forest6))
	else game_param "biom" "desert"
		("tex_rand_%dnum" name1(%desert1) name2(%desert2) name3(%desert3) name4(%desert4) name5(%desert5) name6(%desert6))
	else game_param 	"biom" "city"
		("tex_rand_%cnum" name1(%city1) name2(%city2) name3(%city3) name4(%city4) name5(%city5) name6(%city6))
	}
)

;======== INIT ========

{"texmod_w"
	{on "tex_refresh"
		("select_biom"	snum(1) snow1(win) 				snow2() 	snow3()		snow4()		snow5()		snow6()
						fnum(1)	forest1()				forest2()	forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1() 				desert2() 	desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 				city2() 	city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_f_d"
	{on "tex_refresh"
		("select_biom"	snum(1) snow1(win) 				snow2() 	snow3()		snow4()		snow5()		snow6()
						fnum(1)	forest1(forest)			forest2()	forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1(desert) 		desert2() 	desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 				city2() 	city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cf_cd"
	{on "tex_refresh"
		("select_biom"	snum(1) snow1(win) 					snow2() 	snow3()		snow4()		snow5()		snow6()
						fnum(1)	forest1(camo_forest)		forest2()	forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1(camo_desert) 		desert2() 	desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 	city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_cw_cf_cd"
	{on "tex_refresh"
		("select_biom"	snum(1) snow1(camo_win) 			snow2() 	snow3()		snow4()		snow5()		snow6()
						fnum(1)	forest1(camo_forest)		forest2()	forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1(camo_desert) 		desert2() 	desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 	city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cf_cd_c2d"
	{on "tex_refresh"
		("select_biom"	snum(1) snow1(win) 					snow2() 				snow3()		snow4()		snow5()		snow6()
						fnum(1)	forest1(camo_forest)		forest2()				forest3()	forest4()   forest5()   forest6()
						dnum(2)	desert1(camo_desert) 		desert2(camo2_desert) 	desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 				city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cw_cf_cd"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(win) 					snow2(camo_win) 	snow3()		snow4()		snow5()		snow6()
						fnum(1)	forest1(camo_forest)		forest2()			forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1(camo_desert) 		desert2() 			desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 			city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cf_c2f_cd"
	{on "tex_refresh"
		("select_biom"	snum(1) snow1(win) 					snow2() 				snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(camo2_forest)	forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1(camo_desert) 		desert2() 				desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 				city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cf_c2f_cd_c2d"
	{on "tex_refresh"
		("select_biom"	snum(1) snow1(win) 					snow2() 				snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(camo2_forest)	forest3()	forest4()   forest5()   forest6()
						dnum(2)	desert1(camo_desert) 		desert2(camo2_desert) 	desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 				city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_cw_cf_c2f_cd"
	{on "tex_refresh"
		("select_biom"	snum(1) snow1(camo_win) 			snow2() 				snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(camo2_forest)	forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1(camo_desert) 		desert2() 				desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 				city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cw_cf"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(win) 					snow2(camo_win) 	snow3()		snow4()		snow5()		snow6()
						fnum(1)	forest1(camo_forest)		forest2()			forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1()			 		desert2() 			desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 			city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cf_d_c_gc"
	{on "tex_refresh"
		("select_biom"	snum(1) snow1(win) 					snow2()			 			snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(green_forest)		forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1(desert)			 	desert2() 					desert3()	desert4()   desert5()   desert6()
						cnum(2) city1(city) 				city2(green_city) 			city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cw_cf_c2f_cd_c2d"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(win) 					snow2(camo_win) 			snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(camo2_forest)		forest3()	forest4()   forest5()   forest6()
						dnum(2)	desert1(camo_desert) 		desert2(camo2_desert) 		desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 					city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cw_gw_zw_zcw_zgw_cf_zcf_d_cd_zd_zcd_c_gc_zc_zgc"
	{on "tex_refresh"
		("select_biom"	snum(6) snow1(win) 					snow2(camo_win)				snow3(gray_win)		snow4(zem_win)		snow5(zem_camo_win)		snow6(zem_gray_win)
						fnum(2)	forest1(camo_forest)		forest2(zem_camo_forest)	forest3()			forest4()           		forest5()   forest6()
						dnum(4)	desert1(desert)			 	desert2(camo_desert) 		desert3(zem_desert)	desert4(zem_camo_desert)	desert5()   desert6()
						cnum(4) city1(city) 				city2(gray_city) 			city3(zem_city)		city4(zem_gray_city)        city5()     city6()
		)
	}
}
{"texmod_w_cw_cf_c2f_cd"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(win) 					snow2(camo_win) 			snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(camo2_forest)		forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1(camo_desert) 		desert2() 					desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 					city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cw_cf_c2f_cd_c2d"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(win) 					snow2(camo_win) 			snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(camo2_forest)		forest3()	forest4()   forest5()   forest6()
						dnum(2)	desert1(camo_desert) 		desert2(camo2_desert) 		desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 					city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cw_ow_ocw_cf_ocf_cd_ocd_od_c_oc"
	{on "tex_refresh"
		("select_biom"	snum(4) snow1(win) 					snow2(camo_win) 					snow3(orange_win)		snow4(orange_camo_win)		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(orange_camo_forest)			forest3()				forest4()   forest5()   forest6()
						dnum(3)	desert1(camo_desert) 		desert2(orange_camo_desert) 		desert3(orange_desert)	desert4()   desert5()   desert6()
						cnum(2) city1(city) 				city2(orange_city) 					city3()					city4()     city5()     city6()
		)
	}
}
{"texmod_w_cw_cf_c2f"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(win) 					snow2(camo_win) 				snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(camo2_forest)			forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1() 					desert2() 						desert3()	desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 						city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cf_cd_c_gc"
	{on "tex_refresh"
		("select_biom"	snum(1) snow1(win) 					snow2() 			snow3()		snow4()		snow5()		snow6()
						fnum(1)	forest1(camo_forest)		forest2()			forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1(camo_desert) 		desert2() 			desert3()	desert4()   desert5()   desert6()
						cnum(2) city1(city) 				city2(gray_city) 	city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_zw_cf_zcf_cd_zcd_c_zc"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(win) 					snow2(zem_win) 						snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(zem_camo_forest)			forest3()	forest4()   forest5()   forest6()
						dnum(2)	desert1(camo_desert) 		desert2(zem_camo_desert) 			desert3()	desert4()   desert5()   desert6()
						cnum(2) city1(city) 				city2(zem_city) 					city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_cw_zcw_cf_zcf_cd_zcd_c_zc"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(camo_win) 			snow2(zem_camo_win) 				snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(zem_camo_forest)			forest3()	forest4()   forest5()   forest6()
						dnum(2)	desert1(camo_desert) 		desert2(zem_camo_desert) 			desert3()	desert4()   desert5()   desert6()
						cnum(2) city1(city) 				city2(zem_city) 					city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_gw_f_d_c_gc"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(win) 					snow2(gray_win) 	snow3()		snow4()		snow5()		snow6()
						fnum(1)	forest1(forest)				forest2()			forest3()	forest4()   forest5()   forest6()
						dnum(1)	desert1(desert) 			desert2() 			desert3()	desert4()   desert5()   desert6()
						cnum(2) city1(city) 				city2(gray_city) 	city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_ow_cf_ocf_cd_ocd_c_oc"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(win) 					snow2(orange_win) 				snow3()		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(orange_camo_forest)		forest3()	forest4()   forest5()   forest6()
						dnum(2)	desert1(camo_desert) 		desert2(orange_camo_desert) 	desert3()	desert4()   desert5()   desert6()
						cnum(2) city1(city) 				city2(orange_city) 	city3()		city4()     city5()     city6()
		)
	}
}
{"texmod_w_cw_c2w_cf_c2f_cd_c2d"
	{on "tex_refresh"
		("select_biom"	snum(3) snow1(win) 					snow2(camo_win) 				snow3(camo2_win)		snow4()		snow5()		snow6()
						fnum(2)	forest1(camo_forest)		forest2(camo2_forest)			forest3()				forest4()   forest5()   forest6()
						dnum(2)	desert1(camo_desert) 		desert2(camo2_desert) 			desert3()				desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 						city3()					city4()     city5()     city6()
		)
	}
}
{"texmod_w_cw_cf_c2f_c3f_cd_c2d"
	{on "tex_refresh"
		("select_biom"	snum(2) snow1(win) 					snow2(camo_win) 				snow3()					snow4()		snow5()		snow6()
						fnum(3)	forest1(camo_forest)		forest2(camo2_forest)			forest3(camo3_forest)	forest4()   forest5()   forest6()
						dnum(2)	desert1(camo_desert) 		desert2(camo2_desert) 			desert3()				desert4()   desert5()   desert6()
						cnum(1) city1() 					city2() 						city3()					city4()     city5()     city6()
		)
	}
}