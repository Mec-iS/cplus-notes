/*
Example (NOT WORKING) for declaring a copyable and movable class
 according to the RULE OF FIVE:

 https://en.cppreference.com/w/cpp/language/rule_of_three

*/


// constructor WITHOUT memory allocation
ChatBot::ChatBot()
{
    // invalidate data handles
    _image = nullptr;
    _chatLogic = nullptr;
    _rootNode = nullptr;
}

// constructor WITH memory allocation
ChatBot::ChatBot(std::string filename)
{
    std::cout << "ChatBot Constructor" << std::endl;

    // invalidate data handles
    _chatLogic = nullptr;
    _rootNode = nullptr;

    // load image into heap memory
    _image = new wxBitmap(filename, wxBITMAP_TYPE_PNG);
}

ChatBot::~ChatBot()
{
    std::cout << "ChatBot Destructor" << std::endl;
}


ChatBot::ChatBot(const ChatBot& other) // copy constructor
{
  std::cout << "ChatBot copy constructor" << std::endl;

  _image = other._image;
  _chatLogic = other._chatLogic;
  _rootNode = other._rootNode;
}

ChatBot::ChatBot(ChatBot&& other) noexcept // move constructor
{
  std::cout << "ChatBot move constructor" << std::endl;

  _image = std::move(other._image);
  _chatLogic = std::move(other._chatLogic);
  _rootNode = std::move(other._rootNode);
}

ChatBot& ChatBot::operator=(const ChatBot& other) // copy assignment
{
  std::cout << "ChatBot copy assignment" << std::endl;

  return *this = ChatBot(other);
}

ChatBot& ChatBot::operator=(ChatBot&& other) noexcept // move assignment
{
  std::cout << "ChatBot move assignment" << std::endl;

  std::swap(_image, other._image);
  std::swap(_chatLogic, other._chatLogic);
  std::swap(_rootNode, other._rootNode);
  return *this;
}
