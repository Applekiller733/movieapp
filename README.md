# movieapp

A C++ app which allows operator to choose between access modes (admin/user).

admin access allows operator to add, remove or update elements of the movies list, which the operator can load/save to a JSON file.

user access allows operator to see movies one by one by genre, look at their trailers through a [Youtube link](https://www.youtube.com/) and add movies to their watch list, which they can likewise load/save to a JSON file.

The user's saved watchlist can then be displayed either in Excel or in the user's browser in the form of a table.


## Development

-v0.1 initial commit

-v0.2 switched to using STL vector

-v0.3 fixed filepaths, adapted app to windows, switched to c++11 range-based for loops/other STL methods

-v0.4 added CSV/HTML output file saving and proper display using excel/broswer

-v0.5 added a primitive, yet functional GUI

-v0.51 added very small changes to code and changed GUI style slightly

-v0.6 added polymorphism to repository, more work on GUI

Note: console UI currently unavailable, requires refactoring




##  Roadmap:

  * ~~Adding CSV/HTML output files~~ DONE

  * ~~Refurbishing exceptions/validations in project~~

  * ~~Creating UML Diagram~~ DONE

  * ~~Creating proper GUI~~ basic GUI complete, but further work required

  * Switching from Nlohmann to Qt for json files

  * Adding MySQL database

  * ~~Refactoring Repository to use polymorphism~~

  * Adding web embedding to GUI
