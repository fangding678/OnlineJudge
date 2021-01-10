//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
};

/*
# Write your MySQL query statement below

SELECT
         t2.Request_at 'Day',
         round(avg(t2.Status != 'completed'), 2) 'Cancellation Rate'
FROM
    (SELECT Users_Id
    FROM Users
    WHERE Banned='No'
            AND Role='client') AS t1
JOIN
    (SELECT Id,
         Client_Id,
         Driver_Id,
         `Status`,
         Request_at
    FROM Trips
        WHERE Request_at between '2013-10-01' and '2013-10-03') AS t2
    ON t1.Users_Id = t2.Client_Id
JOIN
    (SELECT Users_Id
    FROM Users
    WHERE Banned='No'
            AND Role='driver') AS t3
    ON t2.Driver_Id = t3.Users_Id
GROUP BY  t2.Request_at

 */

void func() {
    Solution solution;
    string str = "ads";
    cout << str << endl;
}

