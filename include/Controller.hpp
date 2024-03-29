// Copyright 2021 Danil Postvaykin <postvaykin01@mail.ru>

#ifndef INCLUDE_CONTROLLER_HPP_
#define INCLUDE_CONTROLLER_HPP_

#include "Crawler.hpp"
#include "ThreadPool.hpp"
#include <thread>
#include <queue>
#include <string>

class Controller
{
 public:
  Controller(std::string link_f, std::string ref_start,
             int depth, int net_thr, int par_thr);
  void first_download();
  void producer();
  void consumer();
  void out_img();
  ~Controller();
  std::queue<std::string> images;
  std::queue<struct http_parse> http_for_parse;
  std::queue<struct links> collection_links;
 private:
  std::string link_to_start;
  std::string output_ref;
  int max_depth;
  int network_threads;
  int parser_threads;
  std::mutex mut_for_download;
  std::mutex mut_for_parse;
};

#endif  // INCLUDE_CONTROLLER_HPP_
