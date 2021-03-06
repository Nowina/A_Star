#include <consoleinterface.h>

MapGraph *loadMap(){
    int x,y;
    string filename;
    MapGraph *map;
    cout<<"Enter .map file name: ";
    cin>>filename;
    filename = filename+".map";
    ifstream file;
    file.open(filename.c_str(), ios::in);
    if (file.is_open()){
        string line;
        string number;
        getline(file,line);
        for (unsigned int i = 0; i < line.size(); ++i) {
            if (line[i] >= '0' && line[i] < '9'){
                number += line[i];
            }
        }
        x = stoi(number);
        number = "";
        getline(file,line);
        for (unsigned int i = 0; i < line.size(); ++i) {
            if (line[i] >= '0' && line[i] < '9'){
                number += line[i];
            }
        }
        y = stoi(number);
        cout<<"Loaded Map size: "<<x<<" "<<y<<endl;
        map = new MapGraph(x,y);
        y = 0;
        x = 0;
        while (!file.eof()) {
            getline(file,line);
            for (unsigned int i = 0; i < line.size(); i++){
                if (line[i] == '.'){
                    map->getNode(int(i),y)->isObstacle = false;
                }
            }
            y++;
        }
        file.close();
    }
    return map;
}
void setGoalAndStart(MapGraph*&map){
    int xStart,yStart,xGoal,yGoal;
    cout<<"Set start x and y: ";
    cin>>xStart>>yStart;
    while (xStart > map->getDimensions().x || yStart > map->getDimensions().y || !map->getNode(xStart,yStart)->isPassable() ) {
        cout<<"Start cannot be outside map or on obstacle ! Enter valid numbers: "<<"\n";
        cin>>xStart>>yStart;
    }
    map->setStart(xStart,yStart);
    cout<<"Set goal x and y: ";
    cin>>xGoal>>yGoal;
    while (xGoal > map->getDimensions().x || yGoal > map->getDimensions().y || !map->getNode(xGoal,yGoal)->isPassable() ) {
        cout<<"Goal cannot be outside map or on obstacle ! Enter valid numbers: "<<"\n";
        cin>>xGoal>>yGoal;
    }
    map->setGoal(xGoal,yGoal);
}
void printMap(MapGraph* map){
    bool startFound = false;
    bool goalFound  = false;
    location mapDimensions = map->getDimensions();
    location goal = map->getGoal();
    location start = map->getStart();
    int xSize = mapDimensions.x;
    int ySize = mapDimensions.y;
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            GraphNode * node = map->getNode(x,y);
            location nodePosition = node->getPosition();
            if (node->isObstacle){
                cout<<"@";
            }
            else if (nodePosition == goal && !goalFound) {
                cout<<"G";
                goalFound = true;
            }
            else if (nodePosition == start && !startFound){
                cout<<"S";
                startFound = true;
            }
            else {
                cout<<".";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void printMapToFile(MapGraph* map,string filename){
    ofstream file;
    file.open(filename.c_str());
    bool startFound = false;
    bool goalFound  = false;
    location mapDimensions = map->getDimensions();
    location goal = map->getGoal();
    location start = map->getStart();
    int xSize = mapDimensions.x;
    int ySize = mapDimensions.y;
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            GraphNode * node = map->getNode(x,y);
            location nodePosition = node->getPosition();
            if (node->isObstacle){
                file<<"@";
            }
            else if (nodePosition == goal && !goalFound) {
                file<<"G";
                goalFound = true;
            }
            else if (nodePosition == start && !startFound){
                file<<"S";
                startFound = true;
            }
            else {
                file<<".";
            }
        }
        file<<"\n";
    }
    file<<"\n";
}
void printPathToConsole(MapGraph * map, Vector<GraphNode*>*path, double timeTook){
    bool startFound = false;
    bool goalFound  = false;
    location mapDimensions = map->getDimensions();
    location goal = map->getGoal();
    location start = map->getStart();
    int xSize = mapDimensions.x;
    int ySize = mapDimensions.y;
    if (timeTook < 1000){
        cout<<"Path Found !!! Look at it ! :) It took me exactly: "<<timeTook<<"s"<<"\n";
    }
    else {
        cout<<"Path Found !!! Look at it ! :) It took me exactly: "<<timeTook/1000<<"s"<<"\n";
    }
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            GraphNode * node = map->getNode(x,y);
            location nodePosition = node->getPosition();
            bool isOnPath = false;
            for (int i = 0; i < path->getSize(); ++i) {
                if (nodePosition == path->at(i)->data->getPosition()){
                    isOnPath = true;
                }
            }
            if (node->isObstacle){
                cout<<"@";
            }
            else if (nodePosition == goal && !goalFound) {
                cout<<"G";
                goalFound = true;
            }
            else if (nodePosition == start && !startFound){
                cout<<"S";
                startFound = true;
            }
            else if (isOnPath) {
                cout<<"-";
            }
            else {
                cout<<".";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void printPathToFile(MapGraph * map, Vector<GraphNode*>* path, double timeTook,string filename){
    ofstream file;
    file.open(filename.c_str());
    bool startFound = false;
    bool goalFound  = false;
    location mapDimensions = map->getDimensions();
    location goal = map->getGoal();
    location start = map->getStart();
    int xSize = mapDimensions.x;
    int ySize = mapDimensions.y;
    cout<<"Path Found !!! Look at it ! :) It took me exactly: "<<timeTook<<"s"<<"\n";
    cout<<"Now printing path to file..."<<"\n";
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            GraphNode * node = map->getNode(x,y);
            location nodePosition = node->getPosition();
            bool isOnPath = false;
            for (int i = 0; i < path->getSize(); ++i) {
                if (nodePosition == path->at(i)->data->getPosition()){
                    isOnPath = true;
                }
            }
            if (node->isObstacle){
                file<<"@";
            }
            else if (nodePosition == goal && !goalFound) {
                file<<"G";
                goalFound = true;
            }
            else if (nodePosition == start && !startFound){
                file<<"S";
                startFound = true;
            }
            else if (isOnPath) {
                file<<"O";
            }
            else {
                file<<".";
            }
        }
        file<<"\n";
    }
    file<<"\n";
    cout<<"Path is in output.txt file"<<"\n";
}

