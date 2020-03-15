# Style Guide
Paraphrased from the ROS C++ Style Guide.


## 1. Naming Conventions

Only four allowed naming schemes: 

- *CamelCased*: First letter Caps, each new word then starts with Caps, no underscores. 
- *camelCased*: same as above, but first letter no Caps 
- *under_scored*: words all in small letters, each separated by an underscore 
- *UNDER_SCORED*: words all in capital letters, each separated by an underscore

**Package Names**: *under_scored*

**Topic/Service Names**: *under_scored*

**File names**: *under_scored*. Concisely describe the content of the file.\
**Libraries**: *under_scored*. Prefix the name with lib, but don’t add an underscore after lib.

**Class/Type names**: *CamelCased*. Class names should be nouns.
If the name contains any acronyms, they should be all Caps.

**Function names**: *camelCased*. Function names should be verbs.
**Function arguments**: *under_scored*

**Variable names**: *under_scored*. Keep as short and descriptive as possible.\
**Member variable names**: *under_scored*, but with a trailing underscored added.\
**Global variable names**: *under_scored*, but with a leading ‘g_’ added.

**Constant names**: ALL_CAPITALS

**Namespace names**: *under_scored*


## 2. Formatting

**Ctrl-Shift-I** with ROS extension installed on VSCode will do it.\
Choose to *Format on Save* and/or *Format while Typing* for auto-formatting.

## 3. License

Every source and header file must contain a license and copyright statement at the beginning of the file. Refer [this](https://choosealicense.com/) site for more details.

## 4. Include guards

All headers must be protected against multiple inclusion by #ifndef guards, e.g.:

```cpp
#ifndef PACKAGE_PATH_FILE_H
#define PACKAGE_PATH_FILE_H
...
#endif
```
Alternative shorthand:

```cpp
#pragma once
```

This guard should begin immediately after the license statement, before any code, and should end at the end of the file.

## 5. Console output

Use ```ROS_DEBUG```, ```ROS_INFO```, ```ROS_WARN```, ```ROS_ERROR``` and ```ROS_FATAL``` over printf
Append ```_STREAM``` to above for cout-like behaviour. More at [rosconsole Documentation](http://wiki.ros.org/rosconsole).

## 6. Preprocessing

No macros. For conditional compilation, use ```#if``` instead of ```#ifdef``` statements. Rather, don’t use them at all.

## 7. Error Handling

- Always document what exceptions can be thrown by your package, on each function method.
- Don't throw exceptions from destructors.
- Don't throw exceptions from callbacks that you don't invoke directly.
- Deallocate memory when your code is going to terminate after an exception.
Use assertions to check preconditions, data structure integrity, and the return value from a memory allocator. For this, use ```ROS_ASSERT```, ```ROS_ASSERT_MSG```, ```ROS_ASSERT_CMD``` and ```ROS_BREAK```.
- When nearing software completion and when assertions are found to always be true in the face of extensive testing, you build with a flag that removes assertions from compilation, so they take up no space or time. The following option to ```catkin_make``` will define the NDEBUG macro for all your ROS packages, and thereby remove assertion checks.

```bash
catkin_make -DCMAKE_CXX_FLAGS:STRING="-DNDEBUG"
```

cmake will rebuild all your software when you run it with this command, and will remember the setting through subsequent catkin_make runs until you delete your build and devel directories and rebuild. 

## 8. Globals

Globals, both variables and functions, are discouraged. They prevent multiple instantiations of a piece of code and make multi-threaded programming a nightmare. Static class variables are also similiarly discouraged.

Declare most variables and functions inside classes. Enclose the rest inside a namespace.

## 9. Deprecation

To deprecate an entire header file within a package, you may include an appropriate warning:
```cpp
#warning mypkg/my_header.h has been deprecated
```

To deprecate a function, add the deprecated attribute:
```cpp
ROS_DEPRECATED int myFunc(); 
```

To deprecate a class, deprecate its constructor and any static functions.

## 10. Documentation

Apart from comments, it is necessary to maintain a detailed documentation that describes each method provided by the package, along with possible errors and debug solutions. 
