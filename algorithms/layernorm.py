import torch

import torch


class LayerNorm(torch.nn.Module):
    def __init__(self, dimensions, eps: float = 1e-6) -> None:
        super().__init__()
        self.gamma = torch.nn.Parameter(torch.ones(dimensions))
        self.beta = torch.nn.Parameter(torch.zeros(dimensions))
        self.eps = eps

    def forward(self, tensor: torch.Tensor):
        mean = tensor.mean(-1, keepdim=True)
        std = tensor.std(-1, unbiased=False, keepdim=True)
        return self.gamma * (tensor - mean) / (std + self.eps) + self.beta
