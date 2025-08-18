DSU ds(7);
	ds.unionByRank(1,2);
	ds.unionByRank(2,3);
	ds.unionByRank(4,5);
	ds.unionByRank(6,7);
	ds.unionByRank(5,6);

	//checking that 3 and 7 belong to the same component or not 
	if (ds.findUPar(3) == ds.findUPar(7)) {
		cout << "Same\n";
	} else {
		cout << "Not Same\n";
	}

	ds.unionByRank(3,7);

	if (ds.findUPar(3) == ds.findUPar(7)) {
		cout << "Same\n";
	} else {
		cout << "Not Same\n";
	}

