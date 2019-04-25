#include"pch.h"
#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<algorithm>
#include<math.h>
using namespace std;
/*在由 2D 网格表示的校园里有 n 位工人（worker）和 m 辆自行车（bike），n <= m。所有工人和自行车的位置都用网格上的 2D 坐标表示。

我们需要为每位工人分配一辆自行车。在所有可用的自行车和工人中，我们选取彼此之间曼哈顿距离最短的工人自行车对  (worker, bike) ，并将其中的自行车分配給工人。如果有多个 (worker, bike) 对之间的曼哈顿距离相同，那么我们选择工人索引最小的那对。类似地，如果有多种不同的分配方法，则选择自行车索引最小的一对。不断重复这一过程，直到所有工人都分配到自行车为止。

给定两点 p1 和 p2 之间的曼哈顿距离为 Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|。

返回长度为 n 的向量 ans，其中 a[i] 是第 i 位工人分配到的自行车的索引（从 0 开始）。*/
map<int,list<map<int,int>>> workerMatchBike(vector<vector<int>>& workers, vector<vector<int>>& bikes ) {
	map<int, list<map<int, int>>> result;
	int workerIndex = 0;
	for (vector<int>work : workers) {
		int worker[2] = {};
		int i = 0;
		for (int index : work) {
			worker[i] = index;
			i++;
		}
		int bikeIndex = 0;
		for (vector<int>bike : bikes) {
			vector<int>a = bike;
			int bike[2] = {};		
			int j = 0;
			for (int bike_index : a) {
				bike[j] = bike_index;
				j++;
			}
			int bikeToWorkerDis = abs(bike[0] - worker[0]) + abs(bike[1] - worker[1]);
			if (result.find(bikeToWorkerDis) != result.end()) {
				map<int, int> workGetBike;
				workGetBike[workerIndex] = bikeIndex;
				if (workerIndex == 1 && bikeIndex == 2) {
					map<int, list<map<int, int>>> result1;
					result1[bikeToWorkerDis].push_back(workGetBike);
					cout << endl;
				}
		
				result[bikeToWorkerDis].push_back(workGetBike);
			}
			else {
				map<int, int> workGetBike;
				list<map<int, int>>l;
				workGetBike[workerIndex] = bikeIndex;
				l.push_back(workGetBike);
				result[bikeToWorkerDis] = l;
			}
			bikeIndex++;
		}
		workerIndex++;
	}
	return result;
}
void mapAssign(map<int, int>&des, map<int, int>::iterator map_it) {

	map<int, int>::iterator test_it = des.begin();
	if (des.size() == 0) {
		des[map_it->first] = map_it->second;
		return;
	}
	while (test_it != des.end()) {
		if (test_it->second == map_it->second) {
			test_it++;
			return;
		}	
		test_it++;
	}
	des[map_it->first] = map_it->second;
}
vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
	map<int, list<map<int, int>>> specifiedLength = workerMatchBike(workers, bikes);
	vector<int>workerToBike;
	map<int, int>result;
	map<int, list<map<int, int>>>::iterator it;
	//遍历处理map<int, list<map>>
	for (it = specifiedLength.begin(); it != specifiedLength.end(); it++) {
		list<map<int, int>> workerBikeIndex = it->second;
		list<map<int, int>> ::iterator it_list = workerBikeIndex.begin();
		//遍历处理map里面list<map>
		while (it_list != workerBikeIndex.end()) {
			map<int, int>map_buf = *it_list;
			map<int, int>::iterator map_it = map_buf.begin();
			//遍历处理里面的map
			while (map_it != map_buf.end()) {
				if (result.find(map_it->first) != result.end()) {
					map_it++;
					continue;
				}
				else {
					mapAssign(result, map_it);
				}
				map_it++;
			}
			it_list++;
		}
	}

	map<int, int>::iterator test_it = result.begin();
	while (test_it != result.end()) {
		workerToBike.push_back(test_it->second);
		test_it++;
	}
	return workerToBike;
}



int main()
{
	vector<int>woker1 = {0,0};
	vector<int>woker2 = {2,1};
	vector<int>woker3 = {2,0};

	vector<int>bike1 = {1,2 };
	vector<int>bike2 = {3,3 };
	vector<int>bike3 = {2,1 };

	vector<vector<int>>wokers;
	vector<vector<int>>bikes;
	
	wokers.push_back(woker1);
	wokers.push_back(woker2);
	//wokers.push_back(woker3);

	bikes.push_back(bike1);
	bikes.push_back(bike2);
	//bikes.push_back(bike3);

	vector<int>result = assignBikes(wokers,bikes);
	cout << "back to main again" << endl;
	return 0;
}