#include<vector>
using std::vector;
#include<string>
using std::string;
#include<utility>
using std::pair;
#include<sstream>
using std::ostringstream;

#include "proj10_mapset.h"

int main(){
	MapSet<string,long> ms({ {"bill",1},{"alan",2},{"abby",3} });

	size_t result = ms.size();
	size_t ans = 3;
	std::cout << ms << std::endl;
	//std::cout << (result == ans) << std::endl;
	std::cout << result << std::endl;
}