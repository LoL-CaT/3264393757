;SDL
(define "check_year"
{"%cannon_trailer(%side)"
	{content
		{if year "%year"
			{"%transport1"	{"arena_mp/%side/artilleryman"	%nt1}}
		else
			{"%transport2"	{"arena_mp/%side/artilleryman"	%nt2}}
		}
		{"%cannon"			{"arena_mp/%side/artilleryman"	%nc}}
	}
}
)
(define "gaz_aa_vs_gaz67"	("check_year" side(rus) year(before1943) cannon(%c) nc(4) transport1(gaz_aa) nt1(2) transport2(gaz67) nt2(2)))
("gaz_aa_vs_gaz67" c(53k))
("gaz_aa_vs_gaz67" c(m42))
("gaz_aa_vs_gaz67" c(1927_cannon))
("gaz_aa_vs_gaz67" c(1943_cannon))
("gaz_aa_vs_gaz67" c(61k))
("gaz_aa_vs_gaz67" c(kpvt))