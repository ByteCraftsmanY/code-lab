#include <bits/stdc++.h>
using namespace std;
#include "sqlite3.h"
class Mydb
{
   sqlite3 *db;
   static int callback(void *data, int argc, char **argv, char **azColName)
   {
      for (int i = 0; i < argc; i++)
         cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\t";
      cout << endl;
      return 0;
   }

public:
   Mydb() { sqlite3_open("test.db", &db); /*this will open db if not exist then create new one*/ }
   bool createTable()
   {
      sqlite3_stmt *createStmt;
      string createQuery = "CREATE TABLE IF NOT EXISTS Movies (S_No INTEGER PRIMARY KEY AUTOINCREMENT, Movie_Name TEXT,Lead_Actor TEXT,Lead_Actress TEXT,Director TEXT,Year_Of_Release TEXT);";
      sqlite3_prepare(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL); //Creating table
      return (sqlite3_step(createStmt) == SQLITE_DONE);
   }
   vector<string> getQuestions() { return {"Movie Name", "Lead Actor", "Lead Actress", "Director", "Year of release"}; }
   string getInsertQuery() { return "INSERT INTO Movies (Movie_Name,Lead_Actor,Lead_Actress,Director,Year_Of_Release)VALUES ("; }
   bool insertRecord(string insertQuery)
   {
      sqlite3_stmt *insertStmt;
      sqlite3_prepare(db, insertQuery.c_str(), insertQuery.size(), &insertStmt, NULL);
      return (sqlite3_step(insertStmt) == SQLITE_DONE);
   }
   bool selectRecord(string query = "SELECT * FROM Movies;")
   {
      return sqlite3_exec(db, query.c_str(), callback, 0, NULL);
   }
};

int main()
{
   Mydb db;
   bool test = 0;
   test = db.createTable();
   cout << (test ? "*** Table Created ***" : "*** Table Didn't Created! ***") << endl;
   int n;
   cout << "How many movies name you want to insert : ";
   cin >> n;
   cin.ignore();
   for (int i = 1; i <= n; i++)
   {
      string insertQuery = db.getInsertQuery();
      cout << "Movie " << i << endl;
      for (auto qn : db.getQuestions())
      {
         cout << qn << " : ";
         string temp;
         getline(cin, temp);
         insertQuery.append(("'" + temp + "' ,"));
      }
      insertQuery.pop_back();
      insertQuery += ");";
      test = db.insertRecord(insertQuery);
      cout << (test ? "*** Record Inserted ***." : "*** Record Didn't Inserted! ***") << endl;
   }
   cout << "\n\n\n";
   while (true)
   {
      int i = -1;
      string columns = "", column = "", value = "";
      string temp = "SELECT ";
      cout << "Press 0 to see all record\n";
      cout << "Press 1 to record with where condition\n";
      cout << "Press 2 to exit\n";
      cin >> i;
      if (i != -1)
         switch (i)
         {
         case 0:
            db.selectRecord();
            break;
         case 1:
            cin.ignore();
            cout << "Note : For all column write * || for specific column write column name in case of multiple column seperate by ','\nColumns : ";
            getline(cin, columns);
            temp += columns;
            temp += " FROM Movies WHERE ";
            cout << "Now Condition \nColumn : ";
            getline(cin, column);
            cout << "Value : ";
            getline(cin, value);
            temp += (column + " = '" + value + "';");
            cout << "\n"
                 << temp << "\n";
            db.selectRecord(temp);
            break;
         case 2:
            exit(0);
            break;
         default:
            i = -1;
            cout << "Wrong input\n";
         }
      i = -1;
   }
   return 0;
}