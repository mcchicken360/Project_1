Project 1 / Super Warehouse Store
Group Member Names: 
CS008

You are to write a program that services members of Wholesale Club.  You must use a container class with at least one overloaded operator.  You should also describe the growth rate of your program for various operations/functions. At least one class must contain a pointer (a copy constructor needs to be written and tested).   Highlight the above.  Write at least 15 agile stories (including description, tasks, test scenarios, and story points) before you start to develop software.

Wholesale Club has two types of members: basic and preferred. 
Member information includes:
Name
Member number
Membership type
Membership expiration date
Total amount spent
Rebate amount (preferred members only)

A rebate of 5% of the total amount spent (not to include sales tax) is paid at the close of the year to the preferred members. Basic members pay annual dues of $60.00 and preferred members pay annual dues of $75.00. Your program will use the following files that will be provided:

A membership information file that will contain the member name, member number, membership type, and expiration date

Five sales files that contain details of member shopping for a day (member number, items purchased and prices - items not to exceed 100 on any given trip)

Your program should read from the daily sales file and update the members’ information accordingly. As the sales are processed, the total amount spent and rebate data for each member should be updated. Assume a sales tax rate of 8.75%.

Generate the following reports/request at any time:

A sales report for any given day. It should include a list of items and quantities sold on that day as well as names of the members who shopped that day.  Report the total revenue for the given day.  It should also include the number of preferred members and basic members who shopped during the given day.

A yearly sales report.  It should include a list of the items and quantities sold in the given year.  Report the total revenue for the given year.  The report should highlight the best performing items as well as the worst performing items for the year.  

A user should be able to enter a membership number or name and get a list of the total purchases per that member.

A report that prints the total purchases by all the members sorted by membership number.  It should also include a grand total of the purchases.

A user should be able to enter an item name and get the quantity of that item sold as well as the total sales price.

A report that prints out the quantity of each item sold sorted by item name.

A report that prints out the rebate of all the preferred members sorted by membership number.

A report showing the amount per year paid by each member for the membership dues sorted by member type (basic/preferred and then by member name.)

A user should be able to enter a month and get a list of all members whose memberships expire that month as well as their dues amount.

A user should be able to add/delete members. Create purchases for the new members to validate your code. Updates should be saved between executions.

Determine if any basic customer should convert their membership to preferred status.

Determine if any preferred customer should convert their membership to basic status.

Save all changes between executions.

A user should also be able to specify the above reports for basic members only, preferred members only, or all members.

Design a very readable, easy to use graphical interface to demonstrate your program.  Sample daily sales files have been provided for you, but the final project should have much more data than what is provided.  Similarly with the shopper list.  Contingency handling should include addressing invalid input such as invalid membership number, invalid member type, invalid item name, etc.  All projects are due by March 3rd.   No late projects will be accepted. Your team must demonstrate your project to me before it will be graded.   Each teammate must identify their accomplishments on the project.  

Submit an UML class, use case, and state diagrams with your project.
