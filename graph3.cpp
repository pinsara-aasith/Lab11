
int citySizes[100001];
int cityParents[100001];

int findParent(int city)
{
    if (city == cityParents[city])
        return city;
    return cityParents[city] = findParent(cityParents[city]);
}

void groupCities(int cityA, int cityB)
{
    cityA = findParent(cityA);
    cityB = findParent(cityB);
    if (cityA == cityB)
        return;
    if (citySizes[cityA] < citySizes[cityB])
        swap(cityA, cityB);
    cityParents[cityB] = cityA;
    citySizes[cityA] += citySizes[cityB];
}

long roadsAndLibraries(int numCities, int costLibrary, int costRoad, vector<vector<int>> cityConnections)
{
    if (costLibrary <= costRoad)
    {
        return (long)numCities * costLibrary;
    }
    else
    {
        for (int i = 1; i <= numCities; i++)
        {
            citySizes[i] = 1;
            cityParents[i] = i;
        }

        for (auto connection : cityConnections)
        {
            groupCities(connection[0], connection[1]);
        }

        unordered_map<int, bool> visitedCities;
        long long totalCost = 0;

        for (int i = 1; i <= numCities; i++)
        {
            int parent = findParent(i);
            if (visitedCities[parent])
                continue;
            totalCost += costLibrary;
            totalCost += ((citySizes[parent] - 1) * costRoad);
            visitedCities[parent] = true;
        }

        return totalCost;
    }
}