# Algorithms

A repository with clear and readable implementations of common algorithms and data structures.

## Structure

`lib`: third-party libraries

`src`: algorithms and data structures source code

`test`: test code

## Developing and building

We use (and highly recommend) CLion to work with and build this project.

## Writing tests

Use the `TEST_CASE` macro to define a test case. It takes one or two arguments - a free form test name and, optionally,
one or more tags. The test name must be unique.

Inside a test case, use `REQUIRE` and pass to it a condition that should evaluate to true. You can also use `SECTION` to
achieve more elaborate tests. For each `SECTION` the `TEST_CASE` is evaluated from the start. A nested `SECTION` will
run after all its encompassing `SECTION`s.

**All tests should pass**.
