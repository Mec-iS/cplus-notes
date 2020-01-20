/*
Example (NOT WORKING) for declaring a copyable and movable class
 according to the RULE OF FIVE:

 https://en.cppreference.com/w/cpp/language/rule_of_three

*/

// RULE OF FIVE
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

    // deallocate heap memory
    if(_image == NULL || _image == nullptr) {} // Attention: wxWidgets used NULL and not nullptr
    else {
        delete _image;
        _image = NULL;
    }
}

// Copy logic
ChatBot::ChatBot(const ChatBot& other) // copy constructor
{
  std::cout << "ChatBot copy constructor" << std::endl;

  _image = new wxBitmap();
  *_image = *other._image;

  _chatLogic = other._chatLogic;
  _chatLogic->SetChatbotHandle(this);
  _rootNode = other._rootNode;
}

 // move constructor
ChatBot::ChatBot(ChatBot&& other) noexcept
{
  std::cout << "ChatBot move constructor" << std::endl;

  // other is passed with exclusive ownership

  _image = other._image;
  other._image = NULL;

  _chatLogic = other._chatLogic;
  _chatLogic->SetChatbotHandle(this);

  _currentNode = std::move(other._currentNode);
  _chatLogic = std::move(other._chatLogic);
  _rootNode = std::move(other._rootNode);
}

// equality by reference
ChatBot& ChatBot::operator=(const ChatBot& other) // copy assignment
{
  std::cout << "ChatBot copy assignment" << std::endl;

  if (this == &other) // protect agains self-assignment
        return *this;

  _rootNode = other._rootNode;

  _chatLogic = other._chatLogic;
  _chatLogic->SetChatbotHandle(this);

      if (_image != NULL)
          delete _image;

      _image = new wxBitmap();
      *_image = *other._image;

      return *this;
}

// equality when other is moving
ChatBot& ChatBot::operator=(ChatBot&& other) noexcept // move assignment
{
  std::cout << "ChatBot move assignment" << std::endl;

  if (this == &other)
         return *this;

   _rootNode = other._rootNode;

   _chatLogic = other._chatLogic;
   _chatLogic->SetChatbotHandle(this);
   other._chatLogic = NULL;

   if (_image != NULL)
       delete _image;

   _image = other._image;
   other._image = NULL;

   return *this;
}
