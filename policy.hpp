/************************************************************************
 Copyright 2018 andrewpqc@mails.ccnu.edu.cn
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 ************************************************************************/
#ifndef __POLICY_HPP__
#define __POLICY_HPP__

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

class BasePolicy {
 public:
  virtual void open_ostream() = 0;
  virtual void close_ostream() = 0;
  virtual void write(const std::string &msg) = 0;
};

class FilePolicy : public BasePolicy {
 private:
  std::string filename;
  std::unique_ptr<std::ofstream> out_stream;

 public:
  FilePolicy(std::string &f) : filename(f), out_stream(new std::ofstream) {
    this->open_ostream();
  }

  void open_ostream() {
    this->out_stream->open(filename, std::ofstream::out | std::ofstream::app);
  }

  void close_ostream() { this->out_stream->close(); }

  void write(const std::string &msg) {
    *(this->out_stream) << msg << std::endl;
  }
  ~FilePolicy() { this->close_ostream(); }
};

class TerminalPolicy : public BasePolicy {
 public:
  // placehold 保持接口一致
  TerminalPolicy(std::string &placehold){};

  void open_ostream() {
    // do nothing
  }

  void close_ostream() {
    // do nothing
  }

  void write(const std::string &msg) { std::cout << msg << std::endl; }
};

// remaining impl
class RemotePolicy : public BasePolicy {
 private:
  std::string remote_host;
  unsigned short remote_port;

 public:
  RemotePolicy(std::string &addr) {
    auto pos = addr.find_first_of(":");
    this->remote_host = addr.substr(0, pos);
    this->remote_port = atoi(addr.substr(pos + 1).c_str());

    this->open_ostream();
  }

  ~RemotePolicy() { this->close_ostream(); }

  void open_ostream() {
    // do nothing
  }

  void close_ostream() {
    // do nothing
  }

  void write(const std::string &msg) {}
};
#endif