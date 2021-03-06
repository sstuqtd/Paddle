/* Copyright (c) 2016 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once

#ifdef PADDLE_WITH_CUDA

#include <cuda_runtime.h>
#include <stddef.h>
#include <string>

namespace paddle {
namespace platform {

//! Environment variable: fraction of GPU memory to use on each device.
const std::string kEnvFractionGpuMemoryToUse =
    "PADDLE_FRACTION_GPU_MEMORY_TO_USE";

//! Get the total number of GPU devices in system.
int GetCUDADeviceCount();

//! Get the MultiProcessors of the ith GPU.
int GetCUDAMultiProcessors(int i);

//! Get the MaxThreads of each MultiProcessor of the ith GPU.
int GetCUDAMaxThreadsPerMultiProcessor(int i);

//! Get the current GPU device id in system.
int GetCurrentDeviceId();

//! Set the GPU device id for next execution.
void SetDeviceId(int device_id);

//! Get the memory usage of current GPU device.
void GpuMemoryUsage(size_t &available, size_t &total);

//! Get the maximum allocation size of current GPU device.
size_t GpuMaxAllocSize();

//! Get the minimum chunk size for GPU buddy allocator.
size_t GpuMinChunkSize();

//! Get the maximum chunk size for GPU buddy allocator.
size_t GpuMaxChunkSize();

//! Copy memory from address src to dst asynchronously.
void GpuMemcpyAsync(void *dst, const void *src, size_t count,
                    enum cudaMemcpyKind kind, cudaStream_t stream);

//! Copy memory from one device to another device.
void GpuMemcpyPeer(void *dst, int dst_device, const void *src, int src_device,
                   size_t count, cudaStream_t stream);

//! Set memory dst with value count size asynchronously
void GpuMemsetAsync(void *dst, int value, size_t count, cudaStream_t stream);

}  // namespace platform
}  // namespace paddle

#endif
