# Practices

## Consistent memory management

* To this end, the *Rule of Three* states that if a class needs to have an overloaded copy constructor, copy assignment operator, ~or~ destructor, then it must also implement the other two as well to ensure that memory is managed consistently
