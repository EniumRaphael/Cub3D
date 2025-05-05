{
	description = "Shell for 42 cpp";

	inputs = {
		nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
		flake-utils.url = "github:numtide/flake-utils";
		c_formatter_42.url = "github:maix0/c_formatter_42-flake";
	};
	outputs = {
			self,
			nixpkgs,
			flake-utils,
			c_formatter_42
		}:
		flake-utils.lib.eachDefaultSystem (system:
			let
				pkgs = import nixpkgs {
					inherit system;
				};
			in {
				devShells.default = pkgs.mkShell {
					name = "cpp-42";
					buildInputs = with pkgs; [
						c_formatter_42.packages.${system}.default
						clang
						clang-tools
						norminette
						xorg.libX11
						xorg.libXext
					] ++ (
						if pkgs.stdenv.isLinux then [
							valgrind
						] else []
					);
					
					shellHook = ''
						export NIX_SHOW_STATS=0
						export NIX_HIDE_STATS=1
						export C=clang
						export CFLAGS="-std=c89 -Wall -Werror -Wextra"
						printf "\n\033[0;90mC w/MLX env loaded for: \033[38;5;220m${system}\033[0m\n"
					'';
					};
				}
		);
}
