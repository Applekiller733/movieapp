# movieapp

A C++ app which allows operator to choose between access modes (admin/user).

admin access allows operator to add, remove or update elements of the movies list, which the operator can load/save to a JSON file.

user access allows operator to see movies one by one by genre, look at their trailers through a [Youtube link](https://www.youtube.com/) and add movies to their watch list, which they can likewise load/save to a JSON file.



## Development

-v0.1 initial commit

-v0.2 switched to using STL vector

-v0.3 fixed filepaths, adapted app to windows, switched to c++11 range-based for loops/other STL methods

-v0.4 added CSV/HTML output file saving and proper display using excel/broswer

  ~~filepath of the JSON files is (my) full dir path. I will ammend this in the future.~~ No longer an issue




##  Roadmap:

  * ~~Adding CSV/HTML output files~~ DONE

  * Refurbishing exceptions/validations in project

  * Creating UML Diagram

  * Creating proper GUI

  * Switching from Nlohmann to Qt for json files

  * Adding MySQL database
