#include <fstream>

using namespace std;

int main()
{
    ofstream file("bdd.sql");
    fputs(file, "CREATE TABLE test;");
    fputs(file, "ALTER TABLE test ADD id INT;");
    fputs(file, "ALTER TABLE test ADD value INT;");
    
    for(int i = 0; i < 1000000; i++)
    {
        string line = "INSERT INTO test VALUE (" + i + ", " + i + ");)";
        fputs(file, line);
    }
    
    return 0;
}
