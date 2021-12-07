#include <string>
#include <vector>

std::string cart_predict(std::vector<double> features) {
	if (features[481] <= 7.23621) {
		if (features[5] <= 350.1545) {
			if (features[257] <= 168.971) {
				return ( "classical");
			} else {
				if (features[0] <= 43.67185) {
					return ( "jazz");
				} else {
					if (features[0] <= 94.54060000000001) {
						return ( "classical");
					} else {
						return ( "country");
					}
				}
			}
		} else {
			if (features[31] <= 113.40549999999999) {
				if (features[299] <= 56.6939) {
					if (features[7] <= 425.363) {
						if (features[1] <= 138.73255) {
							return ( "classical");
						} else {
							return ( "country");
						}
					} else {
						return ( "blues");
					}
				} else {
					return ( "blues");
				}
			} else {
				if (features[111] <= 59.4848) {
					if (features[226] <= 2.6833099999999996) {
						if (features[342] <= 54.075500000000005) {
							if (features[0] <= 120.88595000000001) {
								return ( "country");
							} else {
								return ( "blues");
							}
						} else {
							if (features[7] <= 332.485) {
								return ( "metal");
							} else {
								return ( "country");
							}
						}
					} else {
						return ( "classical");
					}
				} else {
					if (features[5] <= 803.4455) {
						if (features[0] <= 251.2855) {
							return ( "metal");
						} else {
							return ( "hiphop");
						}
					} else {
						return ( "blues");
					}
				}
			}
		}
	} else {
		if (features[21] <= 223.358) {
			if (features[24] <= 228.525) {
				if (features[76] <= 37.92985) {
					return ( "classical");
				} else {
					return ( "hiphop");
				}
			} else {
				if (features[0] <= 254.12624999999997) {
					return ( "disco");
				} else {
					return ( "jazz");
				}
			}
		} else {
			if (features[57] <= 933.5425) {
				if (features[341] <= 479.529) {
					if (features[354] <= 63.168099999999995) {
						return ( "jazz");
					} else {
						if (features[278] <= 284.5125) {
							if (features[0] <= 341.62649999999996) {
								return ( "rock");
							} else {
								return ( "country");
							}
						} else {
							if (features[0] <= 845.73) {
								if (features[93] <= 940.3865) {
									if (features[267] <= 497.5395) {
										if (features[3] <= 1656.63) {
											return ( "disco");
										} else {
											return ( "rock");
										}
									} else {
										if (features[270] <= 485.6055) {
											return ( "hiphop");
										} else {
											if (features[11] <= 935.6265000000001) {
												return ( "disco");
											} else {
												if (features[0] <= 766.379) {
													return ( "blues");
												} else {
													return ( "pop");
												}
											}
										}
									}
								} else {
									if (features[1] <= 945.7605) {
										return ( "reggae");
									} else {
										return ( "country");
									}
								}
							} else {
								if (features[0] <= 860.011) {
									return ( "metal");
								} else {
									if (features[0] <= 892.6800000000001) {
										return ( "rock");
									} else {
										return ( "hiphop");
									}
								}
							}
						}
					}
				} else {
					if (features[466] <= 487.9085) {
						if (features[206] <= 944.2170000000001) {
							if (features[346] <= 492.534) {
								if (features[474] <= 481.64) {
									if (features[35] <= 933.8175) {
										return ( "jazz");
									} else {
										if (features[0] <= 841.576) {
											return ( "country");
										} else {
											if (features[0] <= 843.3015) {
												return ( "rock");
											} else {
												if (features[0] <= 847.0225) {
													return ( "pop");
												} else {
													return ( "metal");
												}
											}
										}
									}
								} else {
									if (features[48] <= 917.8520000000001) {
										if (features[0] <= 843.8395) {
											return ( "reggae");
										} else {
											if (features[0] <= 856.473) {
												return ( "rock");
											} else {
												return ( "pop");
											}
										}
									} else {
										if (features[34] <= 947.539) {
											return ( "metal");
										} else {
											return ( "country");
										}
									}
								}
							} else {
								if (features[9] <= 936.0854999999999) {
									if (features[2] <= 923.3915) {
										return ( "pop");
									} else {
										if (features[18] <= 935.7950000000001) {
											return ( "disco");
										} else {
											if (features[0] <= 830.4845) {
												return ( "jazz");
											} else {
												if (features[0] <= 843.7719999999999) {
													return ( "metal");
												} else {
													return ( "hiphop");
												}
											}
										}
									}
								} else {
									return ( "country");
								}
							}
						} else {
							if (features[132] <= 932.0160000000001) {
								if (features[0] <= 828.9955) {
									return ( "rock");
								} else {
									if (features[0] <= 834.2055) {
										return ( "country");
									} else {
										if (features[0] <= 840.9325) {
											return ( "reggae");
										} else {
											return ( "disco");
										}
									}
								}
							} else {
								return ( "pop");
							}
						}
					} else {
						if (features[53] <= 939.221) {
							if (features[104] <= 932.5315) {
								if (features[67] <= 922.1469999999999) {
									if (features[20] <= 933.021) {
										return ( "hiphop");
									} else {
										return ( "jazz");
									}
								} else {
									if (features[105] <= 931.4875) {
										return ( "metal");
									} else {
										if (features[10] <= 938.0655) {
											if (features[0] <= 845.0889999999999) {
												return ( "pop");
											} else {
												if (features[0] <= 864.0135) {
													return ( "rock");
												} else {
													return ( "reggae");
												}
											}
										} else {
											return ( "disco");
										}
									}
								}
							} else {
								if (features[123] <= 923.3935) {
									if (features[0] <= 857.4694999999999) {
										return ( "metal");
									} else {
										return ( "jazz");
									}
								} else {
									if (features[6] <= 942.6855) {
										return ( "rock");
									} else {
										return ( "disco");
									}
								}
							}
						} else {
							if (features[21] <= 930.7315) {
								if (features[2] <= 952.5895) {
									return ( "pop");
								} else {
									return ( "country");
								}
							} else {
								if (features[42] <= 931.7905000000001) {
									return ( "reggae");
								} else {
									if (features[3] <= 921.8520000000001) {
										return ( "jazz");
									} else {
										if (features[3] <= 926.119) {
											return ( "pop");
										} else {
											if (features[0] <= 846.2545) {
												return ( "rock");
											} else {
												if (features[0] <= 852.3225) {
													return ( "disco");
												} else {
													return ( "country");
												}
											}
										}
									}
								}
							}
						}
					}
				}
			} else {
				if (features[494] <= 476.8435) {
					if (features[233] <= 919.5360000000001) {
						if (features[0] <= 979.6645) {
							return ( "jazz");
						} else {
							return ( "country");
						}
					} else {
						if (features[1] <= 961.8495) {
							if (features[1] <= 928.0564999999999) {
								return ( "rock");
							} else {
								if (features[0] <= 847.1510000000001) {
									if (features[0] <= 843.6965) {
										return ( "pop");
									} else {
										return ( "disco");
									}
								} else {
									if (features[0] <= 856.1435) {
										return ( "country");
									} else {
										if (features[0] <= 864.048) {
											return ( "jazz");
										} else {
											if (features[0] <= 869.8475) {
												return ( "metal");
											} else {
												return ( "reggae");
											}
										}
									}
								}
							}
						} else {
							return ( "hiphop");
						}
					}
				} else {
					if (features[133] <= 947.698) {
						if (features[402] <= 479.835) {
							if (features[93] <= 942.442) {
								if (features[49] <= 938.5415) {
									if (features[19] <= 924.707) {
										if (features[0] <= 836.6279999999999) {
											return ( "rock");
										} else {
											return ( "pop");
										}
									} else {
										return ( "country");
									}
								} else {
									if (features[41] <= 972.2885) {
										return ( "jazz");
									} else {
										return ( "reggae");
									}
								}
							} else {
								return ( "rock");
							}
						} else {
							if (features[250] <= 938.461) {
								if (features[245] <= 943.2674999999999) {
									if (features[149] <= 949.3295) {
										if (features[425] <= 478.73) {
											if (features[66] <= 926.4884999999999) {
												if (features[0] <= 847.4159999999999) {
													return ( "rock");
												} else {
													return ( "jazz");
												}
											} else {
												if (features[70] <= 921.634) {
													return ( "country");
												} else {
													return ( "reggae");
												}
											}
										} else {
											if (features[249] <= 926.7080000000001) {
												if (features[47] <= 932.498) {
													return ( "disco");
												} else {
													return ( "rock");
												}
											} else {
												if (features[390] <= 478.269) {
													return ( "metal");
												} else {
													return ( "reggae");
												}
											}
										}
									} else {
										return ( "rock");
									}
								} else {
									if (features[490] <= 484.0295) {
										return ( "reggae");
									} else {
										if (features[161] <= 928.7915) {
											if (features[2] <= 934.7435) {
												return ( "metal");
											} else {
												return ( "hiphop");
											}
										} else {
											return ( "pop");
										}
									}
								}
							} else {
								if (features[376] <= 489.1085) {
									if (features[138] <= 937.0609999999999) {
										if (features[3] <= 941.4085) {
											if (features[1] <= 932.2135) {
												if (features[0] <= 828.537) {
													return ( "disco");
												} else {
													return ( "hiphop");
												}
											} else {
												return ( "pop");
											}
										} else {
											return ( "jazz");
										}
									} else {
										return ( "rock");
									}
								} else {
									return ( "disco");
								}
							}
						}
					} else {
						if (features[19] <= 925.4385) {
							if (features[0] <= 827.0425) {
								return ( "reggae");
							} else {
								return ( "jazz");
							}
						} else {
							return ( "pop");
						}
					}
				}
			}
		}
	}
}