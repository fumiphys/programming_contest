# auto create snippet
In file, you should write
```
// begin library {library_name} here
// {how_to_use}
{contents_of_the_library}
// end library
```

then create snippet like
```
snippet {library_name}_def
  {contents_of_the_library}
snippet {library_name}_use
  {how_to_use}
```
