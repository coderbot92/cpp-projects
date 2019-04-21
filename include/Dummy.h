#pragma once

#include <iostream>

namespace sample {

/// \brief This is a dummy class to demonstrate the project setup for build.
class Dummy
{
public:

  /// \brief Creates a Dummy instance.
  Dummy() = default;

  /// \brief Destroys a Dummy instance.
  virtual ~Dummy() = default;

  /// \brief Computes the absolute value.
  /// \param value the input number
  /// \return the absolute value
  int absolute(int value);
};

} /* namespace sample */
