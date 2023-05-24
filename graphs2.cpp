#include <iostream>
#include <vector>
#include <map>

using namespace std;

class City
{
public:
    int label;
    bool visited = false;
    vector<int> connected_cities;
};

long search_for_neighbours(int city_label, map<int, City *> &city_map)
{
    long cities_count = 0;
    City *city = city_map[city_label];
    city->visited = true;

    cities_count++;

    for (int neighbour_label : city->connected_cities)
    {
        City *neighbour = city_map[neighbour_label];

        if (!neighbour->visited)
        {
            cities_count += search_for_neighbours(neighbour_label, city_map);
        }
    }

    return cities_count;
}

long calculate_cost(int c_lib, int c_road, map<int, City *> &city_map)
{
    long cost = 0;

    auto it = city_map.begin();
    while (it != city_map.end())
    {
        auto city = it->second;

        if (!city->visited)
        {
            long citiesCount = search_for_neighbours(city->label, city_map);
            // cost += (c_lib + (citiesCount - 1) * min(c_lib, c_road));

            if (c_lib * citiesCount < c_lib + c_road * (citiesCount - 1))
            {
                cost += c_lib * citiesCount;
            }
            else
            {
                cost += c_lib + c_road * (citiesCount - 1);
            }
        }

        it++;
    }

    return cost;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
    // If cost for roard is greater than cost for library
    if (c_lib <= c_road)
    {
        return n * c_lib;
    }

    map<int, City *> city_map;

    for (int i = 1; i <= n; i++)
    {
        City *city = new City();
        city->label = i;
        city->visited = false;
        city_map[i] = city;
    }

    for (vector<int> city_connection : cities)
    {
        city_map[city_connection[0]]->connected_cities.push_back(city_connection[1]);
        city_map[city_connection[1]]->connected_cities.push_back(city_connection[0]);
    }

    return calculate_cost(c_lib, c_road, city_map);
}

int main()
{
}
