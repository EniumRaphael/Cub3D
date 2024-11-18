{
  description = "Flake utils demo";

  inputs = {
	nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
    c_formatter_42.url = "github:maix0/c_formatter_42-flake";
  };
  outputs = {
    self,
    nixpkgs,
    flake-utils,
    c_formatter_42,
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = nixpkgs.legacyPackages.${system};
      in {
        devShell = pkgs.mkShell {
          packages = [
           pkgs.xorg.libX11
            pkgs.xorg.libXext
            pkgs.clang
            pkgs.clang-tools
            pkgs.norminette
            c_formatter_42.packages.${system}.default
            ];
        };
      }
    );
}
