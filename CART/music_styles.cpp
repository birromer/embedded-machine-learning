#include <string>
#include <vector>

std::string cart_predict(std::vector<double> features) {
	if (features[376] <= 8.575344999999999) {
		if (features[3] <= 428.4355) {
			if (features[273] <= 11.1051) {
				return ( "jazz");
			} else {
				if (features[444] <= 5.26204) {
					return ( "classical");
				} else {
					if (features[0] <= 63.03045) {
						return ( "jazz");
					} else {
						return ( "classical");
					}
				}
			}
		} else {
			if (features[0] <= 81.56495) {
				return ( "country");
			} else {
				return ( "blues");
			}
		}
	} else {
		if (features[488] <= 2.572305) {
			if (features[262] <= 519.9395) {
				if (features[10] <= 433.46000000000004) {
					if (features[47] <= 117.10900000000001) {
						if (features[410] <= 25.874200000000002) {
							if (features[9] <= 252.22050000000002) {
								if (features[55] <= 33.5189) {
									return ( "blues");
								} else {
									if (features[0] <= 53.5059) {
										return ( "classical");
									} else {
										return ( "jazz");
									}
								}
							} else {
								return ( "country");
							}
						} else {
							return ( "blues");
						}
					} else {
						if (features[0] <= 251.2855) {
							return ( "metal");
						} else {
							return ( "hiphop");
						}
					}
				} else {
					if (features[44] <= 161.015) {
						return ( "country");
					} else {
						return ( "blues");
					}
				}
			} else {
				if (features[463] <= 13.3923) {
					if (features[9] <= 920.6475) {
						if (features[119] <= 5.87714) {
							return ( "country");
						} else {
							return ( "blues");
						}
					} else {
						return ( "country");
					}
				} else {
					if (features[259] <= 1063.71) {
						if (features[3] <= 875.0840000000001) {
							return ( "hiphop");
						} else {
							return ( "country");
						}
					} else {
						if (features[0] <= 479.47450000000003) {
							return ( "blues");
						} else {
							return ( "hiphop");
						}
					}
				}
			}
		} else {
			if (features[23] <= 223.77800000000002) {
				if (features[344] <= 62.96254999999999) {
					if (features[14] <= 330.1325) {
						if (features[70] <= 39.733599999999996) {
							return ( "classical");
						} else {
							if (features[21] <= 160.909) {
								return ( "hiphop");
							} else {
								return ( "disco");
							}
						}
					} else {
						return ( "jazz");
					}
				} else {
					if (features[0] <= 164.5275) {
						if (features[0] <= 136.07150000000001) {
							return ( "disco");
						} else {
							return ( "country");
						}
					} else {
						if (features[15] <= 460.6845) {
							if (features[48] <= 262.921) {
								return ( "hiphop");
							} else {
								return ( "disco");
							}
						} else {
							return ( "country");
						}
					}
				}
			} else {
				if (features[13] <= 455.5215) {
					if (features[2] <= 2097.54) {
						return ( "disco");
					} else {
						if (features[0] <= 771.2774999999999) {
							if (features[1] <= 1816.1399999999999) {
								if (features[0] <= 145.78699999999998) {
									return ( "disco");
								} else {
									if (features[0] <= 379.8315) {
										return ( "jazz");
									} else {
										return ( "rock");
									}
								}
							} else {
								return ( "country");
							}
						} else {
							return ( "hiphop");
						}
					}
				} else {
					if (features[289] <= 498.1305) {
						if (features[80] <= 83.0122) {
							return ( "classical");
						} else {
							if (features[281] <= 263.54499999999996) {
								return ( "country");
							} else {
								if (features[274] <= 488.5425) {
									if (features[192] <= 916.0515) {
										if (features[264] <= 491.57849999999996) {
											if (features[5] <= 927.489) {
												if (features[0] <= 597.0675) {
													return ( "hiphop");
												} else {
													return ( "reggae");
												}
											} else {
												return ( "rock");
											}
										} else {
											if (features[1] <= 926.2745) {
												return ( "rock");
											} else {
												return ( "jazz");
											}
										}
									} else {
										if (features[288] <= 476.173) {
											if (features[5] <= 922.925) {
												return ( "pop");
											} else {
												return ( "metal");
											}
										} else {
											if (features[404] <= 483.1745) {
												if (features[43] <= 924.0685000000001) {
													return ( "metal");
												} else {
													return ( "pop");
												}
											} else {
												if (features[397] <= 477.3095) {
													return ( "disco");
												} else {
													return ( "metal");
												}
											}
										}
									}
								} else {
									if (features[250] <= 931.896) {
										if (features[233] <= 918.8455) {
											if (features[3] <= 956.878) {
												if (features[65] <= 932.013) {
													return ( "hiphop");
												} else {
													return ( "jazz");
												}
											} else {
												if (features[60] <= 949.001) {
													return ( "disco");
												} else {
													return ( "metal");
												}
											}
										} else {
											if (features[278] <= 484.5565) {
												if (features[240] <= 933.598) {
													return ( "pop");
												} else {
													return ( "disco");
												}
											} else {
												if (features[425] <= 488.1615) {
													return ( "reggae");
												} else {
													return ( "rock");
												}
											}
										}
									} else {
										if (features[173] <= 937.277) {
											if (features[284] <= 491.6205) {
												if (features[107] <= 942.9155000000001) {
													return ( "pop");
												} else {
													return ( "disco");
												}
											} else {
												if (features[7] <= 929.72) {
													return ( "jazz");
												} else {
													return ( "country");
												}
											}
										} else {
											if (features[383] <= 489.275) {
												if (features[308] <= 491.95550000000003) {
													return ( "metal");
												} else {
													return ( "country");
												}
											} else {
												if (features[57] <= 930.7895000000001) {
													return ( "rock");
												} else {
													return ( "disco");
												}
											}
										}
									}
								}
							}
						}
					} else {
						if (features[76] <= 959.0685) {
							if (features[40] <= 937.6034999999999) {
								if (features[85] <= 931.5875) {
									return ( "hiphop");
								} else {
									if (features[17] <= 935.913) {
										if (features[14] <= 934.816) {
											return ( "jazz");
										} else {
											if (features[0] <= 839.018) {
												return ( "metal");
											} else {
												return ( "reggae");
											}
										}
									} else {
										return ( "rock");
									}
								}
							} else {
								if (features[84] <= 934.777) {
									if (features[434] <= 481.5375) {
										return ( "jazz");
									} else {
										if (features[45] <= 942.7635) {
											if (features[54] <= 945.127) {
												return ( "reggae");
											} else {
												return ( "disco");
											}
										} else {
											if (features[27] <= 959.288) {
												if (features[0] <= 1002.608) {
													return ( "country");
												} else {
													return ( "pop");
												}
											} else {
												return ( "rock");
											}
										}
									}
								} else {
									if (features[389] <= 496.5935) {
										return ( "reggae");
									} else {
										return ( "jazz");
									}
								}
							}
						} else {
							if (features[65] <= 943.3489999999999) {
								return ( "rock");
							} else {
								return ( "jazz");
							}
						}
					}
				}
			}
		}
	}
}