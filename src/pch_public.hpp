#pragma once

#include <exception>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <thread>
#include <mutex>
#include <memory>
#include <utility>
#include <optional>
// spd
#include <spdlog/spdlog.h>
// GLM
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
// GLM Mat
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
// GLM Constants
#include <glm/ext/scalar_constants.hpp>
#include <glm/gtc/type_ptr.hpp>
