#include <string>
#include <vector>

std::string cart_predict(std::vector<double> features) {
	if (features[375] <= 7.9915) {
		if (features[258] <= 359.14549999999997) {
			return ( "classical");
		} else {
			if (features[0] <= 37.4563) {
				return ( "country");
			} else {
				return ( "jazz");
			}
		}
	} else {
		if (features[486] <= 1.8685200000000002) {
			if (features[477] <= 3.234495) {
				if (features[262] <= 295.027) {
					if (features[157] <= 6.63488) {
						return ( "country");
					} else {
						if (features[1] <= 231.959) {
							return ( "classical");
						} else {
							if (features[3] <= 462.2635) {
								return ( "jazz");
							} else {
								if (features[0] <= 126.60740000000001) {
									return ( "blues");
								} else {
									return ( "metal");
								}
							}
						}
					}
				} else {
					if (features[34] <= 110.9185) {
						if (features[279] <= 53.94135) {
							if (features[0] <= 243.9635) {
								return ( "country");
							} else {
								return ( "blues");
							}
						} else {
							return ( "blues");
						}
					} else {
						if (features[118] <= 28.4026) {
							if (features[5] <= 1054.15) {
								if (features[286] <= 215.091) {
									if (features[0] <= 107.37565000000001) {
										return ( "classical");
									} else {
										return ( "metal");
									}
								} else {
									return ( "country");
								}
							} else {
								return ( "blues");
							}
						} else {
							if (features[7] <= 381.2045) {
								return ( "hiphop");
							} else {
								return ( "blues");
							}
						}
					}
				}
			} else {
				if (features[105] <= 64.44655) {
					if (features[274] <= 196.2295) {
						if (features[0] <= 262.234) {
							return ( "blues");
						} else {
							return ( "hiphop");
						}
					} else {
						return ( "country");
					}
				} else {
					if (features[6] <= 609.499) {
						if (features[0] <= 214.4955) {
							return ( "metal");
						} else {
							if (features[0] <= 369.96750000000003) {
								return ( "country");
							} else {
								return ( "hiphop");
							}
						}
					} else {
						if (features[8] <= 467.1435) {
							return ( "hiphop");
						} else {
							return ( "blues");
						}
					}
				}
			}
		} else {
			if (features[46] <= 303.562) {
				if (features[257] <= 1266.475) {
					if (features[192] <= 16.4554) {
						if (features[310] <= 122.681) {
							if (features[249] <= 4.384755) {
								return ( "jazz");
							} else {
								if (features[10] <= 191.0305) {
									return ( "hiphop");
								} else {
									return ( "classical");
								}
							}
						} else {
							return ( "classical");
						}
					} else {
						if (features[59] <= 233.9325) {
							if (features[24] <= 172.2535) {
								if (features[111] <= 35.1075) {
									if (features[0] <= 375.0225) {
										return ( "country");
									} else {
										return ( "disco");
									}
								} else {
									if (features[0] <= 163.59699999999998) {
										return ( "disco");
									} else {
										return ( "hiphop");
									}
								}
							} else {
								if (features[272] <= 576.953) {
									if (features[0] <= 674.6535) {
										if (features[8] <= 235.15699999999998) {
											return ( "hiphop");
										} else {
											return ( "disco");
										}
									} else {
										return ( "blues");
									}
								} else {
									if (features[0] <= 523.1355) {
										return ( "jazz");
									} else {
										return ( "blues");
									}
								}
							}
						} else {
							return ( "country");
						}
					}
				} else {
					if (features[306] <= 75.08445) {
						return ( "jazz");
					} else {
						if (features[159] <= 97.5076) {
							if (features[276] <= 690.3045) {
								if (features[353] <= 170.45749999999998) {
									return ( "hiphop");
								} else {
									return ( "disco");
								}
							} else {
								return ( "disco");
							}
						} else {
							return ( "disco");
						}
					}
				}
			} else {
				if (features[279] <= 502.1735) {
					if (features[407] <= 469.557) {
						if (features[4] <= 1353.145) {
							if (features[297] <= 489.192) {
								return ( "country");
							} else {
								if (features[0] <= 482.7555) {
									return ( "classical");
								} else {
									return ( "reggae");
								}
							}
						} else {
							return ( "rock");
						}
					} else {
						if (features[405] <= 499.17100000000005) {
							if (features[288] <= 486.72) {
								if (features[108] <= 943.182) {
									if (features[62] <= 923.0654999999999) {
										if (features[394] <= 489.423) {
											if (features[433] <= 481.087) {
												if (features[1] <= 930.1795) {
													return ( "metal");
												} else {
													return ( "country");
												}
											} else {
												if (features[5] <= 910.895) {
													return ( "disco");
												} else {
													return ( "pop");
												}
											}
										} else {
											if (features[2] <= 935.774) {
												return ( "country");
											} else {
												if (features[0] <= 834.0935) {
													return ( "reggae");
												} else {
													return ( "jazz");
												}
											}
										}
									} else {
										if (features[429] <= 475.495) {
											if (features[100] <= 931.827) {
												if (features[0] <= 835.7395) {
													return ( "jazz");
												} else {
													return ( "disco");
												}
											} else {
												return ( "pop");
											}
										} else {
											if (features[190] <= 929.5185) {
												if (features[437] <= 477.02) {
													return ( "reggae");
												} else {
													return ( "pop");
												}
											} else {
												if (features[283] <= 486.56899999999996) {
													return ( "metal");
												} else {
													return ( "metal");
												}
											}
										}
									}
								} else {
									if (features[59] <= 942.181) {
										if (features[2] <= 954.69) {
											return ( "pop");
										} else {
											return ( "disco");
										}
									} else {
										if (features[0] <= 848.3085) {
											if (features[0] <= 832.4300000000001) {
												return ( "metal");
											} else {
												if (features[0] <= 841.082) {
													return ( "disco");
												} else {
													return ( "reggae");
												}
											}
										} else {
											return ( "hiphop");
										}
									}
								}
							} else {
								if (features[53] <= 950.9685) {
									if (features[164] <= 940.677) {
										if (features[329] <= 482.34450000000004) {
											if (features[473] <= 493.865) {
												if (features[262] <= 480.30949999999996) {
													return ( "pop");
												} else {
													return ( "disco");
												}
											} else {
												return ( "metal");
											}
										} else {
											if (features[414] <= 481.51099999999997) {
												if (features[349] <= 495.75149999999996) {
													return ( "jazz");
												} else {
													return ( "disco");
												}
											} else {
												if (features[340] <= 493.911) {
													return ( "metal");
												} else {
													return ( "reggae");
												}
											}
										}
									} else {
										if (features[254] <= 940.0015) {
											if (features[101] <= 940.1755) {
												if (features[221] <= 941.448) {
													return ( "rock");
												} else {
													return ( "metal");
												}
											} else {
												if (features[0] <= 848.3015) {
													return ( "disco");
												} else {
													return ( "pop");
												}
											}
										} else {
											if (features[70] <= 941.28) {
												if (features[2] <= 924.156) {
													return ( "reggae");
												} else {
													return ( "metal");
												}
											} else {
												return ( "jazz");
											}
										}
									}
								} else {
									if (features[334] <= 495.659) {
										if (features[276] <= 480.5365) {
											if (features[0] <= 834.3330000000001) {
												return ( "disco");
											} else {
												if (features[0] <= 838.9955) {
													return ( "reggae");
												} else {
													return ( "hiphop");
												}
											}
										} else {
											if (features[11] <= 948.2565) {
												return ( "rock");
											} else {
												return ( "jazz");
											}
										}
									} else {
										return ( "pop");
									}
								}
							}
						} else {
							if (features[95] <= 940.7715000000001) {
								return ( "rock");
							} else {
								if (features[0] <= 859.3455) {
									return ( "metal");
								} else {
									return ( "disco");
								}
							}
						}
					}
				} else {
					if (features[6] <= 1012.14) {
						if (features[116] <= 939.831) {
							if (features[260] <= 594.038) {
								if (features[113] <= 943.5) {
									return ( "reggae");
								} else {
									return ( "country");
								}
							} else {
								if (features[0] <= 888.3415) {
									return ( "jazz");
								} else {
									return ( "hiphop");
								}
							}
						} else {
							if (features[12] <= 952.427) {
								if (features[0] <= 891.767) {
									return ( "pop");
								} else {
									return ( "hiphop");
								}
							} else {
								return ( "jazz");
							}
						}
					} else {
						if (features[481] <= 481.78200000000004) {
							return ( "jazz");
						} else {
							if (features[10] <= 1027.195) {
								return ( "rock");
							} else {
								if (features[0] <= 955.01) {
									return ( "reggae");
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